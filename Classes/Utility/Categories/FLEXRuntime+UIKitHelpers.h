//
//  FLEXRuntime+UIKitHelpers.h
//  FLEX
//
//  Created by Tanner Bennett on 12/16/19.
//  Copyright © 2019 Flipboard. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FLEXUtility.h"
#import "FLEXProperty.h"
#import "FLEXIvar.h"
#import "FLEXMethod.h"
#import "FLEXProtocol.h"

@protocol FLEXRuntimeMetadata <NSObject>
/// Used as the main title of the row
- (NSString *)description;
/// Used to compare metadata objects for uniqueness
@property (nonatomic, readonly) NSString *name;
/// YES for properties and ivars which surely support editing, NO for all methods.
@property (nonatomic, readonly) BOOL isEditable;
/// NO for ivars, YES for supported methods and properties
@property (nonatomic, readonly) BOOL isCallable;

/// For internal use
@property (nonatomic) id tag;

/// Should return \c nil if not applicable
- (id)currentValueWithTarget:(id)object;
/// Used as the subtitle or description of a property, ivar, or method
- (NSString *)previewWithTarget:(id)object;
/// For methods, a method calling screen. For all else, an object explorer.
- (UIViewController *)viewerWithTarget:(id)object;
/// For methods and protocols, nil. For all else, an a field editor screen.
- (UIViewController *)editorWithTarget:(id)object;
/// Used to determine present which interactions are possible to the user
- (UITableViewCellAccessoryType)suggestedAccessoryTypeWithTarget:(id)object;
/// Return nil to use the default reuse identifier
- (NSString *)reuseIdentifierWithTarget:(id)object;

#if FLEX_AT_LEAST_IOS13_SDK

/// An array of actions to place in the first section of the context menu.
- (NSArray<UIAction *> *)additionalActionsWithTarget:(id)object sender:(UIViewController *)sender API_AVAILABLE(ios(13.0));
/// An array where every 2 elements are a key-value pair. The key is a description
/// of what to copy like "Name" and the values are what will be copied.
- (NSArray<NSString *> *)copiableMetadataWithTarget:(id)object;
/// Properties and ivars return the address of an object, if they hold one.
- (NSString *)contextualSubtitleWithTarget:(id)object;

#endif

@end

// Even if a property is readonly, it still may be editable
// via a setter. Checking isEditable will not reflect that
// unless the property was initialized with a class.
@interface FLEXProperty (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXIvar (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXMethodBase (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXMethod (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXProtocol (UIKitHelpers) <FLEXRuntimeMetadata> @end

typedef NS_ENUM(NSUInteger, FLEXStaticMetadataRowStyle)
{
    FLEXStaticMetadataRowStyleSubtitle,
    FLEXStaticMetadataRowStyleKeyValue,
    FLEXStaticMetadataRowStyleDefault = FLEXStaticMetadataRowStyleSubtitle,
};

/// Displays a small row as a static key-value pair of information.
@interface FLEXStaticMetadata : NSObject <FLEXRuntimeMetadata>

+ (instancetype)style:(FLEXStaticMetadataRowStyle)style title:(NSString *)title string:(NSString *)string;
+ (instancetype)style:(FLEXStaticMetadataRowStyle)style title:(NSString *)title number:(NSNumber *)number;

+ (NSArray<FLEXStaticMetadata *> *)classHierarchy:(NSArray<Class> *)classes;

@end
