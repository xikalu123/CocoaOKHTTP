//
//  OKHTTPInterceptor.h
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>
#import "OKHTTPRequest.h"
#import "OKHTTPResponse.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OKHTTPInterceptorChainProtocol <NSObject>

- (OKHTTPResponse *)request;

@end



@protocol OKHTTPInterceptorProtocol <NSObject>


@end

@interface OKHTTPInterceptor : NSObject

@end

NS_ASSUME_NONNULL_END
