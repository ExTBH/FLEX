//
//  NSObject+IvarReflection.h
//  
//
//  Created by Natheer on 13/04/2023.
//

#import <Foundation/Foundation.h>


@interface NSObject (IvarReflection)
- (id)reflectIvarNamed:(NSString*)name;

@end

