//
//  RUSynthesizeUserDefaultMethods.h
//  Albumatic
//
//  Created by Benjamin Maer on 2/2/13.
//  Copyright (c) 2013 Resplendent G.P. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RUSynthesizeSetUserDefaultsMethodCompletion(varName,key,completion) \
-(void)set##varName:(id)varName \
{ \
    NSUserDefaults* userDefaults = [NSUserDefaults standardUserDefaults]; \
    if (varName) [userDefaults setObject:varName forKey:key]; \
    else [userDefaults removeObjectForKey:key]; \
    [userDefaults synchronize]; \
    if (completion) \
    { \
        void (^completionBlock)() = completion; \
        completionBlock(varName); \
    } \
}

#define RUSynthesizeSetUserDefaultsMethod(varName,key) \
RUSynthesizeSetUserDefaultsMethodCompletion(varName,key,nil)

#define RUSynthesizeGetUserDefaultsMethod(varName,key) \
-(id)varName \
{ \
    NSUserDefaults* userDefaults = [NSUserDefaults standardUserDefaults]; \
    return [userDefaults objectForKey:key]; \
}
