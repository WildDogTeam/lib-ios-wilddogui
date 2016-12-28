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

/**
 * A protocol to allow instances of WilddogArray to raise events through a delegate. Raises all
 * Wilddog events except WEventTypeValue.
 */
@protocol WilddogArrayDelegate<NSObject>

@optional

/**
 * Delegate method which is called whenever an object is added to a WilddogArray. On a
 * WilddogArray synchronized to a Wilddog reference, this corresponds to an
 * [WDGDataEventTypeChildAdded](https://docs.wilddog.com/api/sync/ios/WDGDataEventType.html)
 * event being raised.
 * @param object The object added to the WilddogArray
 * @param index The index the child was added at
 */
- (void)childAdded:(id)object atIndex:(NSUInteger)index;

/**
 * Delegate method which is called whenever an object is chinged in a WilddogArray. On a
 * WilddogArray synchronized to a Wilddog reference, this corresponds to an
 * [WDGDataEventTypeChildChanged](https://docs.wilddog.com/api/sync/ios/WDGDataEventType.html)
 * event being raised.
 * @param object The object that changed in the WilddogArray
 * @param index The index the child was changed at
 */
- (void)childChanged:(id)object atIndex:(NSUInteger)index;

/**
 * Delegate method which is called whenever an object is removed from a WilddogArray. On a
 * WilddogArray synchronized to a Wilddog reference, this corresponds to an
 * [WDGDataEventTypeChildRemoved](https://docs.wilddog.com/api/sync/ios/WDGDataEventType.html)
 * event being raised.
 * @param object The object removed from the WilddogArray
 * @param index The index the child was removed at
 */
- (void)childRemoved:(id)object atIndex:(NSUInteger)index;

/**
 * Delegate method which is called whenever an object is moved within a WilddogArray. On a
 * WilddogArray synchronized to a Wilddog reference, this corresponds to an
 * [WDGDataEventTypeChildMoved](https://docs.wilddog.com/api/sync/ios/WDGDataEventType.html)
 * event being raised.
 * @param object The object that has moved locations in the WilddogArray
 * @param fromIndex The index the child is being moved from
 * @param toIndex The index the child is being moved to
 */
- (void)childMoved:(id)object fromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

@end
