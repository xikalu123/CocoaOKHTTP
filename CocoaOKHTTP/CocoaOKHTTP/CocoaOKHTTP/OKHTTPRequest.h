//
//  OKHTTPRequest.h
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OKHTTPRequest : NSObject

- (BOOL)isValid:(NSError**)err;

@end

@interface OKHTTPRequestBuilder : NSObject

- (nullable OKHTTPRequest*)build;

@end

NS_ASSUME_NONNULL_END

