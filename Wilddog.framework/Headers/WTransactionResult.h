//
//  WTransactionResult.h
//  Wilddog
//
//  Created by Garin on 15/7/10.
//  Copyright (c) 2015年 Wilddog. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMutableData.h"

@interface WTransactionResult : NSObject

/**
 * Used for runTransactionBlock:. Indicates that the new value should be saved at this location
 *
 * @param value An FMutableData instance containing the new value to be set
 * @return An FTransactionResult instance that can be used as a return value from the block given to runTransactionBlock:
 */
+ (WTransactionResult *) successWithValue:(WMutableData *)value;


/**
 * Used for runTransactionBlock:. Indicates that the current transaction should no longer proceed.
 *
 * @return An FTransactionResult instance that can be used as a return value from the block given to runTransactionBlock:
 */
+ (WTransactionResult *) abort;
@end
