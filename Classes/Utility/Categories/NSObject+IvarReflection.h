//
//  NSObject+IvarReflection.h
//  
//
//  Created by ExTBH on 13/04/2023.
//

#import <Foundation/Foundation.h>


@interface NSObject (IvarReflection)
- (nullable id)reflectIvarNamed:( NSString* _Nonnull)name;

@end

