//
//  CMRequest+Protected.h
//  Cumulus
//
//  Created by John Clayton on 11/23/11.
//  Copyright (c) 2011 Fivesquare Software, LLC. All rights reserved.
//

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of Fivesquare Software nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL FIVESQUARE SOFTWARE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** Methods intended for subclasses to access and override. */
@interface CMRequest()

+ (void) incrementRequestCountFor:(id)context;
+ (void) decrementRequestCountFor:(id)context;


// Readwrite versions of readonly props

@property (readwrite, strong) id result;

@property (readwrite) BOOL started;
@property (readwrite) BOOL finished;
@property (readwrite) BOOL canceled;
@property (readonly, getter = didComplete) BOOL completed;
@property (readwrite, strong) NSDate *startedAt;
@property (readwrite, strong) NSDate *endedAt;


@property (readwrite, strong) NSHTTPURLResponse *URLResponse;
@property (readwrite, strong) NSString *responseBody;
@property (nonatomic, strong) CMResponse *responseInternal;



// Private properties

@property (nonatomic, readonly) NSString *fileExtension;
@property BOOL connectionFinished;
@property (readwrite, weak) NSURLConnection *connection;
@property (nonatomic, strong) NSURLRequest *originalURLRequest;
@property (weak) NSTimer *timeoutTimer;
@property (getter = requestIsConfigured) BOOL requestConfigured;
@property (readonly) BOOL canStart;
@property (readonly) BOOL canCancel;
@property (readonly) BOOL canAbort;
@property (nonatomic, readonly) NSString *cacheIdentifier;
@property long long lastChunkSize;

// Helpers

- (void) configureURLRequest:(NSMutableURLRequest *)URLRequest;
- (void) postProcessResponse:(CMResponse *)response;

// Connection event handlers

- (void) handleConnectionWillStart;
- (void) handleConnectionFinished;
- (void) handleConnectionDidReceiveResponse;
- (void) handleConnectionDidReceiveData;
- (void) handleConnectionDidSendData;

@end
