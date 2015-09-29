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

#import <UIKit/UIKit.h>
#import <WilddogUI/XCodeMacros.h>

#import <WilddogUI/WilddogDataSource.h>

@class Wilddog;

/**
 * WilddogTableViewDataSource provides an class that conforms to the
 * UITableViewDataSource protocol
 * which allows UITableViews to implement WilddogTableViewDataSource in order
 * to provide a
 * UITableView synchronized to a Wilddog reference or query. In addition to
 * handling all Wilddog
 * child events (added, changed, removed, moved), WilddogTableViewDataSource
 * handles
 * UITableViewCell creation, either with the default UITableViewCell, prototype
 * cells, custom
 * UITableViewCell subclasses, or custom XIBs, and provides a simple
 * [WilddogTableViewDataSource
 * populateCellWithBlock:] method which allows developers to populate the cells
 * created for them
 * with desired data from Wilddog.
 */
@interface WilddogTableViewDataSource
    : WilddogDataSource<UITableViewDataSource>

/**
 * The model class to coerce WDataSnapshots to (if desired). For instance, if
 * the modelClass is set
 * to [Message class] in Obj-C or Message.self in Swift, then objects of type
 * Message will be
 * returned instead of type WDataSnapshot.
 */
@property(strong, nonatomic, __NON_NULL) Class modelClass;

/**
 * The reuse identifier for cells in the UITableView.
 */
@property(strong, nonatomic, __NON_NULL) NSString *reuseIdentifier;

/**
 * The UITableView instance that operations (inserts, removals, moves, etc.) are
 * performed against.
 */
@property(strong, nonatomic, __NON_NULL) UITableView *tableView;

/**
 * Property to keep track of prototype cell use, to not register a class for the
 * UICollectionView or
 * do similar book keeping.
 */
@property BOOL hasPrototypeCell;

/**
 * The callback to populate a subclass of UITableViewCell with an object
 * provided by the datasource.
 */
@property(strong, nonatomic, __NON_NULL) void (^populateCell)
    (__KINDOF(UITableViewCell) __NON_NULL_PTR cell,
     __KINDOF(NSObject) __NON_NULL_PTR object);

/**
 * Initialize an instance of WilddogTableViewDataSource that populates
 * UITableViewCells with
 * WDataSnapshots.
 * @param ref A Wilddog reference to bind the datasource to
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates
 * UITableViewCells with
 * WDataSnapshots
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates
 * UITableViewCells with
 * WDataSnapshots. Note that this method is used when using prototype cells,
 * where the cells don't
 * need to be registered in the class.
 * @param ref A Wilddog reference to bind the datasource to
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates
 * UITableViewCells with
 * WDataSnapshots
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
              prototypeReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates a custom
 * subclass of
 * UITableViewCell with WDataSnapshots.
 * @param ref A Wilddog reference to bind the datasource to
 * @param cell A subclass of UITableViewCell used to populate the UITableView,
 * defaults to
 * UITableViewCell if nil
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates a custom
 * subclass of
 * UITableViewCell with WDataSnapshots
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                             cellClass:(__NULLABLE Class)cell
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates a custom
 * xib with
 * WDataSnapshots.
 * @param ref A Wilddog reference to bind the datasource to
 * @param nibName The name of a xib file to create the layout for a
 * UITableViewCell
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates a custom
 * xib with
 * WDataSnapshots
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                              nibNamed:(__NON_NULL NSString *)nibName
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates
 * UITableViewCells with a
 * custom model class.
 * @param ref A Wilddog reference to bind the datasource to
 * @param model A custom class that WDataSnapshots are coerced to, defaults to
 * WDataSnapshot if nil
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates
 * UITableViewCells with a custom
 * model class
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                            modelClass:(__NULLABLE Class)model
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates
 * UITableViewCells with a
 * custom model class. Note that this method is used when using prototype cells,
 * where the cells
 * don't need to be registered in the class.
 * @param ref A Wilddog reference to bind the datasource to
 * @param model A custom class that WDataSnapshots are coerced to, defaults to
 * WDataSnapshot if nil
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates
 * UITableViewCells with a custom
 * model class
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                            modelClass:(__NULLABLE Class)model
              prototypeReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates a custom
 * subclass of
 * UITableViewCell with a custom model class.
 * @param ref A Wilddog reference to bind the datasource to
 * @param model A custom class that WDataSnapshots are coerced to, defaults to
 * WDataSnapshot if nil
 * @param cell A subclass of UITableViewCell used to populate the UITableView,
 * defaults to
 * UITableViewCell if nil
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates a custom
 * subclass of
 * UITableViewCell with a custom model class
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                            modelClass:(__NULLABLE Class)model
                             cellClass:(__NULLABLE Class)cell
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * Initialize an instance of WilddogTableViewDataSource that populates a custom
 * xib with a custom
 * model class.
 * @param ref A Wilddog reference to bind the datasource to
 * @param model A custom class that WDataSnapshots are coerced to, defaults to
 * WDataSnapshot if nil
 * @param nibName The name of a xib file to create the layout for a
 * UITableViewCell
 * @param identifier A string to use as a CellReuseIdentifier
 * @param tableView An instance of a UITableView to bind to
 * @return An instance of WilddogTableViewDataSource that populates a custom
 * xib with a custom
 * model class
 */
- (__NON_NULL instancetype)initWithRef:(__NON_NULL Wilddog *)ref
                            modelClass:(__NULLABLE Class)model
                              nibNamed:(__NON_NULL NSString *)nibName
                   cellReuseIdentifier:(__NON_NULL NSString *)identifier
                                  view:(__NON_NULL UITableView *)tableView;

/**
 * This method populates the fields of a UITableViewCell or subclass given a
 * model object (or
 * WDataSnapshot).
 * @param callback A block which returns an initialized UITableViewCell (or
 * subclass) and the
 * corresponding object to populate the cell with.
 */
- (void)populateCellWithBlock:
    (__NON_NULL void (^)(__KINDOF(UITableViewCell)__NON_NULL_PTR cell,
                         __KINDOF(NSObject)__NON_NULL_PTR object))callback;

@end
