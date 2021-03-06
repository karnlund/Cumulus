//
//  CMOAuthToken.m
//  Cumulus
//
//  Created by John Clayton on 12/19/11.
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
 * 3. Neither the name of Fivesquare Software, LLC nor the names of its contributors may
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

#import "CMOAuthToken.h"

@implementation CMOAuthToken


- (void)encodeWithCoder:(NSCoder *)aCoder {
	[aCoder encodeObject:self.accessToken forKey:@"accessToken"];
	[aCoder encodeObject:self.refreshToken forKey:@"refreshToken"];
	[aCoder encodeObject:self.accessExpires forKey:@"tokenExpiration"];
	[aCoder encodeObject:self.scope forKey:@"scope"];
}

- (id)initWithCoder:(NSCoder *)aDecoder {
	self.accessToken = [aDecoder decodeObjectForKey:@"accessToken"];
	self.refreshToken = [aDecoder decodeObjectForKey:@"refreshToken"];
	self.accessExpires = [aDecoder decodeObjectForKey:@"tokenExpiration"];
	self.scope = [aDecoder decodeObjectForKey:@"scope"];
	
	return self;
}

- (NSString *) description {
	return [NSString stringWithFormat:@"%@ (accessToken: %@, refreshToken: %@, accessExpires: %@, scope: %@)",[super description],_accessToken,_refreshToken,_accessExpires,_scope];
}

@end
