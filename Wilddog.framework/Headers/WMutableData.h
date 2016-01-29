//
//  WMutableData.h
//  Wilddog
//
//  Created by Garin on 15/7/10.
//  Copyright (c) 2015年 Wilddog. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WMutableData : NSObject


/** @name Inspecting and navigating the data */


/**
 * Returns boolean indicating whether this mutable data has children.
 *
 * @return YES if this data contains child nodes.
 */
- (BOOL) hasChildren;


/**
 * Indicates whether this mutable data has a child at the given path.
 *
 * @param path A path string, consisting either of a single segment, like 'child', or multiple segments, 'a/deeper/child'
 * @return YES if this data contains a child at the specified relative path
 */
- (BOOL) hasChildAtPath:(NSString *)path;


/**
 * Used to obtain an FMutableData instance that encapsulates the data at the given relative path.
 * Note that changes made to the child will be visible to the parent.
 *
 * @param path A path string, consisting either of a single segment, like 'child', or multiple segments, 'a/deeper/child'
 * @return An FMutableData instance containing the data at the given path
 */
- (WMutableData *) childDataByAppendingPath:(NSString *)path;


/** @name Properties */


/**
 * To modify the data contained by this instance of FMutableData, set this to any of the native types support by Wilddog:
 *
 * * NSNumber (includes BOOL)
 * * NSDictionary
 * * NSArray
 * * NSString
 * * nil / NSNull to remove the data
 *
 * Note that setting the value will override the priority at this location.
 *
 * @return The current data at this location as a native object
 */
@property (strong, nonatomic) id value;


/**
 * Set this property to update the priority of the data at this location. Can be set to the following types:
 *
 * * NSNumber
 * * NSString
 * * nil / NSNull to remove the priority
 *
 * @return The priority of the data at this location
 */
@property (strong, nonatomic) id priority;


/**
 * @return The number of child nodes at this location
 */
@property (readonly, nonatomic) NSUInteger childrenCount;


/**
 * Used to iterate over the children at this location. You can use the native for .. in syntax:
 *
 * for (FMutableData* child in data.children) {
 *     ...
 * }
 *
 * Note that this enumerator operates on an immutable copy of the child list. So, you can modify the instance
 * during iteration, but the new additions will not be visible until you get a new enumerator.
 */
@property (readonly, nonatomic, strong) NSEnumerator* children;


/**
 * @return The key name of this node, or nil if it is the top-most location
 */
@property (readonly, nonatomic, strong) NSString* key;
@end


















