//
//  NSObject+IvarReflection.h
//  
//
//  Created by ExTBH on 13/04/2023.
//

#import <Foundation/Foundation.h>


@interface NSObject (IvarReflection)
- (id)reflectIvarNamed:( NSString*)name;

@end

