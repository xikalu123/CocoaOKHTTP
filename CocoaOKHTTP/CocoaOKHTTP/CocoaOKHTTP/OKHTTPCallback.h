//
//  OKHTTPCallback.h
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OKHTTPResponse.h"

NS_ASSUME_NONNULL_BEGIN

@protocol OKHTTPCallbackProtocol <NSObject>



@end

@interface OKHTTPCallback : NSObject

+ (instancetype)callbackWithBlockOnResponse:(void (^)(OKHTTPResponse *resp, id<OKHTTPCallbackProtocol> call))respBlock
                                  OnFailure:(void (^)(NSError *error, id<OKHTTPCallbackProtocol> call))failBlock;

+ (instancetype)callbackWithBlockOnResponse:(void (^)(OKHTTPResponse *resp, id<OKHTTPCallbackProtocol> call))respBlock
                                  OnFailure:(void (^)(NSError *error, id<OKHTTPCallbackProtocol> call))failBlock
                                      queue:(dispatch_queue_t)queue;

@end

NS_ASSUME_NONNULL_END
