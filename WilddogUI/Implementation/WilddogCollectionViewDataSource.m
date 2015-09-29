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

#import <Wilddog/Wilddog.h>

#import "WilddogCollectionViewDataSource.h"

@implementation WilddogCollectionViewDataSource

#pragma mark -
#pragma mark WilddogDataSource initializer methods

- (instancetype)initWithRef:(Wilddog *)ref
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  return [self initWithRef:ref
                modelClass:nil
                 cellClass:nil
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
   prototypeReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  self.hasPrototypeCell = YES;
  return [self initWithRef:ref
                modelClass:nil
                 cellClass:nil
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
                  cellClass:(Class)cell
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  return [self initWithRef:ref
                modelClass:nil
                 cellClass:cell
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
                   nibNamed:(NSString *)nibName
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  return [self initWithRef:ref
                modelClass:nil
                  nibNamed:nibName
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
                 modelClass:(Class)model
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  return [self initWithRef:ref
                modelClass:model
                 cellClass:nil
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
                 modelClass:(Class)model
   prototypeReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  self.hasPrototypeCell = YES;
  return [self initWithRef:ref
                modelClass:model
                 cellClass:nil
       cellReuseIdentifier:identifier
                      view:collectionView];
}

- (instancetype)initWithRef:(Wilddog *)ref
                 modelClass:(Class)model
                  cellClass:(Class)cell
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  WilddogArray *array = [[WilddogArray alloc] initWithRef:ref];
  self = [super initWithArray:array];
  if (self) {
    if (!model) {
      model = [WDataSnapshot class];
    }

    if (!cell) {
      cell = [UICollectionViewCell class];
    }

    self.collectionView = collectionView;
    self.modelClass = model;
    self.cellClass = cell;
    self.reuseIdentifier = identifier;
    self.populateCell = ^(id cell, id object) {
    };

    if (!self.hasPrototypeCell) {
      [self.collectionView registerClass:self.cellClass
              forCellWithReuseIdentifier:self.reuseIdentifier];
    }
  }
  return self;
}

- (instancetype)initWithRef:(Wilddog *)ref
                 modelClass:(Class)model
                   nibNamed:(NSString *)nibName
        cellReuseIdentifier:(NSString *)identifier
                       view:(UICollectionView *)collectionView {
  WilddogArray *array = [[WilddogArray alloc] initWithRef:ref];
  self = [super initWithArray:array];
  if (self) {
    if (!model) {
      model = [WDataSnapshot class];
    }

    self.collectionView = collectionView;
    self.modelClass = model;
    self.reuseIdentifier = identifier;
    self.populateCell = ^(id cell, id object) {
    };

    UINib *nib = [UINib nibWithNibName:nibName bundle:nil];
    [self.collectionView registerNib:nib
          forCellWithReuseIdentifier:self.reuseIdentifier];
  }
  return self;
}

#pragma mark -
#pragma mark WilddogCollectionDelegate methods

- (void)childAdded:(id)obj atIndex:(NSUInteger)index {
  [self.collectionView insertItemsAtIndexPaths:@[
    [NSIndexPath indexPathForItem:index inSection:0]
  ]];
}

- (void)childChanged:(id)obj atIndex:(NSUInteger)index {
  [self.collectionView reloadItemsAtIndexPaths:@[
    [NSIndexPath indexPathForRow:index inSection:0]
  ]];
}

- (void)childRemoved:(id)obj atIndex:(NSUInteger)index {
  [self.collectionView deleteItemsAtIndexPaths:@[
    [NSIndexPath indexPathForRow:index inSection:0]
  ]];
}

- (void)childMoved:(id)obj
         fromIndex:(NSUInteger)fromIndex
           toIndex:(NSUInteger)toIndex {
  [self.collectionView
      moveItemAtIndexPath:[NSIndexPath indexPathForRow:fromIndex inSection:0]
              toIndexPath:[NSIndexPath indexPathForRow:toIndex inSection:0]];
}

#pragma mark -
#pragma mark UICollectionViewDataSource methods

- (nonnull UICollectionViewCell *)
        collectionView:(nonnull UICollectionView *)collectionView
cellForItemAtIndexPath:(nonnull NSIndexPath *)indexPath {
  id cell = [self.collectionView
      dequeueReusableCellWithReuseIdentifier:self.reuseIdentifier
                                forIndexPath:indexPath];

  WDataSnapshot *snap = [self.array objectAtIndex:indexPath.row];
  if (![self.modelClass isSubclassOfClass:[WDataSnapshot class]]) {
    id model = [[self.modelClass alloc] init];
    // TODO: replace setValuesForKeysWithDictionary with client API
    // valueAsObject method
    [model setValuesForKeysWithDictionary:snap.value];
    self.populateCell(cell, model);
  } else {
    self.populateCell(cell, snap);
  }

  return cell;
}

- (NSInteger)numberOfSectionsInCollectionView:
    (nonnull UICollectionView *)collectionView {
  return 1;
}

- (NSInteger)collectionView:(nonnull UICollectionView *)collectionView
     numberOfItemsInSection:(NSInteger)section {
  return [self.array count];
}

- (void)populateCellWithBlock:
    (__NON_NULL void (^)(__KINDOF(UICollectionViewCell)__NON_NULL_PTR cell,
                         __KINDOF(NSObject)__NON_NULL_PTR object))callback {
  self.populateCell = callback;
}

@end
