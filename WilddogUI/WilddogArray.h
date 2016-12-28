// clang-format off

/*
 * Wilddog UI Bindings iOS Library
 *
 * Copyright © 2015 Wilddog - All Rights Reserved
 * https://www.Wilddog.com
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binaryform must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY Wilddog AS IS AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL Wilddog BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// clang-format on

#import <Foundation/Foundation.h>
#import <WilddogUI/XCodeMacros.h>

#import <WilddogUI/WilddogArrayDelegate.h>

@class WDGSyncReference;
@class WDGDataSnapshot;

/**
 * WilddogArray provides an array structure that is synchronized with a Wilddog reference or
 * query. It is useful for building custom data structures or sources, and provides the base for
 * WilddogDataSource.
 */
@interface WilddogArray : NSObject

/**
 * The delegate object that array changes are surfaced to, which conforms to the
 * [WilddogArrayDelegate Protocol](WilddogArrayDelegate).
 */
@property(weak, nonatomic) id<WilddogArrayDelegate> delegate;

/**
 * The query on a Wilddog reference that provides data to populate the instance of WilddogArray.
 */
@property(strong, nonatomic) WDGSyncReference *query;

/**
 * The delegate object that array changes are surfaced to.
 */
@property(strong, nonatomic) NSMutableArray __GENERIC(WDGDataSnapshot *) * snapshots;

#pragma mark -
#pragma mark Initializer methods

/**
 * Intitalizes WilddogArray with a standard Wilddog reference.
 * @param ref The Wilddog reference which provides data to WilddogArray
 * @return The instance of WilddogArray
 */
- (instancetype)initWithRef:(WDGSyncReference *)ref;

/**
 * Intitalizes WilddogArray with a Wilddog query (WQuery).
 * @param query A query on a Wilddog reference which provides filtered data to WilddogArray
 * @return The instance of WilddogArray
 */
- (instancetype)initWithQuery:(WDGSyncReference *)query;

#pragma mark -
#pragma mark Public API methods

/**
 * Returns the count of objects in the WilddogArray.
 * @return The count of objects in the WilddogArray
 */
- (NSUInteger)count;

/**
 * Returns an object at a specific index in the WilddogArray.
 * @param index The index of the item to retrieve
 * @return The object at the given index
 */
- (id)objectAtIndex:(NSUInteger)index;

/**
 * Returns a Wilddog reference for an object at a specific index in the WilddogArray.
 * @param index The index of the item to retrieve a reference for
 * @return A Wilddog reference for the object at the given index
 */
- (WDGSyncReference *)refForIndex:(NSUInteger)index;

#pragma mark -
#pragma mark Private API methods

/**
 * Returns an index for a given object's key (that matches the object's key in the corresponding
 * Wilddog reference).
 * @param key The key of the desired object
 * @return The index of the object for which the key matches or -1 if the key is null
 * @exception WilddogArrayKeyNotFoundException Thrown when the desired key is not in the
 * WilddogArray, likely indicating that the WilddogArray is no longer being properly synchronized
 * with the Wilddog database.
 */
- (NSUInteger)indexForKey:(NSString *)key;

@end
