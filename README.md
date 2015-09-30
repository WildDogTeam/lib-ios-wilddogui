# WilddogUI for iOS — UI Bindings for Wilddog

WilddogUI is an open-source library for iOS that allows you to quickly connect common UI elements to the [Wilddog](https://www.wilddog.com/?utm_source=wilddogui-ios) database for data storage, allowing views to be updated in realtime as they change, and providing simple interfaces for common tasks like displaying lists or collections of items.


## Getting Started with Wilddog

WilddogUI requires Wilddog in order to store location data. You can [sign up here for a free
account](https://www.wilddog.com/my-account/signup).

## WilddogUI for iOS Quickstart

This is a quickstart on how to use WilddogUI's core features to speed up iOS development with Wilddog. WilddogUI includes the following features:

Class  | Description
------------- | -------------
WilddogTableViewDataSource | Data source to bind a Wilddog query to a UITableView
WilddogCollectionViewDataSource | Data source to bind a Wilddog query to a UICollectionView
WilddogArray | Keeps an array synchronized to a Wilddog query
WilddogDataSource | Generic superclass to create a custom data source

For a more in-depth explanation of each of the above, check the usage instructions below or read the [docs](http://wilddogui.wilddogapp.com/docs/ios/index.html).

### WilddogTableViewDataSource

`WilddogTableViewDataSource` implements the `UITableViewDataSource` protocol to automatically use Wilddog as a data source for your `UITableView`.

#### Objective-C
```objective-c
YourViewController.h
...
@property (strong, nonatomic) Wilddog *wilddogRef;
@property (strong, nonatomic) WilddogTableViewDataSource *dataSource;
```

```objective-c
YourViewController.m
...
self.wilddogRef = [[Wilddog alloc] initWithUrl:@"https://<YOUR-WILDDOG-APP>.wilddogio.com/"];
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.textLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```


### WilddogCollectionViewDataSource

`WilddogCollectionViewDataSource` implements the `UICollectionViewDataSource` protocol to automatically use Wilddog as a data source for your `UICollectionView`.

#### Objective-C
```objective-c
YourViewController.h
...
@property (strong, nonatomic) Wilddog *wilddogRef;
@property (strong, nonatomic) WilddogCollectionViewDataSource *dataSource;
```

```objective-c
YourViewController.m
...
self.wilddogRef = [[Wilddog alloc] initWithUrl:@"https://<YOUR-WILDDOG-APP>.wilddogio.com/"];
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.backgroundColor = [UIColor blueColor];
}];

[self.collectionView setDataSource:self.dataSource];
```


## Customizing your UITableView or UICollectionView

You can use `WilddogTableViewDataSource` or `WilddogCollectionViewDataSource` in several ways to create custom UITableViews or UICollectionViews. For more information on how to create custom UITableViews, check out the following tutorial on [TutsPlus](http://code.tutsplus.com/tutorials/ios-sdk-crafting-custom-uitableview-cells--mobile-15702). For more information on how to create custom UICollectionViews, particularly how to implement a UICollectionViewLayout, check out the following tutorial on Ray Wenderlich in [Objective-C](http://www.raywenderlich.com/22324/beginning-uicollectionview-in-ios-6-part-12).

### Using the Default UI*ViewCell Implementation

You can use the default `UITableViewCell` or `UICollectionViewCell` implementations to get up and running quickly. For `UITableViewCell`s, this allows for the `cell.textLabel` and the `cell.detailTextLabel` to be used directly out of the box. For `UICollectionViewCell`s, you will have to add subviews to the contentView in order for it to be useful.

#### Objective-C UITableView and UICollectionView with Default UI*ViewCell
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.textLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectioneViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDataSnapshot *snap) {
  // Populate cell as you see fit by adding subviews as appropriate
  [cell.contentView addSubview:customView];
}];

[self.collectionView setDataSource:self.dataSource];
```

### Using Storyboards and Prototype Cells

Create a storyboard that has either a `UITableViewController`, `UICollectionViewController` or a `UIViewController` with a `UITableView` or `UICollectionView`. Drag a prototype cell onto the `UITableView` or `UICollectionView` and give it a custom reuse identifier which matches the reuse identifier being used when instantiating the `Wilddog*ViewDataSource`. When using prototype cells, make sure to use `prototypeReuseIdentifier` instead of `cellReuseIdentifier`.

Drag and other properties onto the cell and associate them with properties of a `UITableViewCell` or `UICollectionViewCell` subclass. Code samples are otherwise similar to the above.

### Using a Custom Subclass of UI*ViewCell

Create a custom subclass of `UITableViewCell` or `UICollectionViewCell`, with or without the XIB file. Make sure to instantiate `-initWithStyle: reuseIdentifier:` to instantiate a `UITableViewCell` or `-initWithFrame:` to instantiate a `UICollectionViewCell`. You can then hook the custom class up to the implementation of `WilddogTableViewDataSource`.

#### Objective-C UITableView and UICollectionView with Custom Subclasses of UI*ViewCell
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellClass:[YourCustomClass class] cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(YourCustomClass *cell, WDataSnapshot *snap) {
  // Populate custom cell as you see fit, like as below
  cell.yourCustomLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectioneViewDataSource alloc] initWithRef:wilddogRef cellClass:[YourCustomClass class] cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(YourCustomClass *cell, WDataSnapshot *snap) {
  // Populate cell as you see fit
  cell.customView = customView;
}];

[self.collectionView setDataSource:self.dataSource];
```

### Using a Custom XIB

Create a custom XIB file and hook it up to the prototype cell. You can then use this like any other UITableViewCell, either using custom tags or by using the custom class associated with the XIB.

#### Objective-C UITableView and UICollectionView with Custom XIB
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef nibNamed:@"<YOUR-XIB>" cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDataSnapshot *snap) {
  // Use tags to populate custom properties, or use properties of a custom cell, if applicable
  UILabel *yourCustomLabel = (UILabel *)[cell.contentView viewWithTag:<YOUR-TAG>];
  yourCustomLabel.text = snap.key
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectionViewDataSource alloc] initWithRef:wilddogRef nibNamed:@"<YOUR-XIB>" cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.collectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDataSnapshot *snap) {
  // Use tags to populate custom properties, or use properties of a custom cell, if applicable
  UILabel *yourCustomLabel = (UILabel *)[cell.contentView viewWithTag:<YOUR-TAG>];
  yourCustomLabel.text = snap.key
}];

[self.tableView setDataSource:self.dataSource];
```

## Understanding WilddogUI's Internals

WilddogUI has several building blocks that developers should understand before building additional functionality on top of WilddogUI, including a synchronized array `WilddogArray` and a generic data source superclass `WilddogDataSource` from which `WilddogTableViewDataSource` and `WilddogCollectionViewDataSource` or other custom view classes subclass.

### WilddogArray and the WilddogArrayDelegate Protocol

`WilddogArray` is synchronized array connecting a Wilddog Ref with an array. It surfaces Wilddog events through the WilddogArrayDelegate Protocol. It is generally recommended that developers not directly access `WilddogArray` without routing it through a custom data source, though if this is desired, check out `WilddogDataSource` below.

#### Objective-C
```objective-c
Wilddog *wilddogRef = [[Wilddog alloc] initWithUrl:@"https://<YOUR-WILDDOG-APP>.wilddogio.com/"];
WilddogArray *array = [[WilddogArray alloc] initWithRef:wilddogRef];
```


### WilddogDataSource

WilddogDataSource acts as a generic data source by providing common information, such as the count of objects in the data source, and by requiring subclasses to implement WilddogArrayDelegate methods as appropriate to the view. This class should never be instantiated, but should be subclassed when creating a specific adapter for a View. [WilddogTableViewDataSource](https://github.com/WildDogTeam/WilddogUI-iOS/blob/master/WilddogUI/Implementation/WilddogTableViewDataSource.m) and [WilddogCollectionViewDataSource](https://github.com/WildDogTeam/WilddogUI-iOS/blob/master/WilddogUI/Implementation/WilddogCollectionViewDataSource.m) are examples of this. WilddogDataSource is essentially a wrapper around a WilddogArray.

## 支持
如果在使用过程中有任何问题，请提 [issue](https://github.com/WildDogTeam/lib-ios-wilddogui/issues) ，我会在 Github 上给予帮助。

## 相关文档

* [Wilddog 概览](https://z.wilddog.com/overview/guide)
* [iOS SDK快速入门](https://z.wilddog.com/ios/quickstart)
* [iOS SDK 开发向导](https://z.wilddog.com/ios/guide/1)
* [iOS SDK API](https://z.wilddog.com/ios/api)
* [下载页面](https://www.wilddog.com/download/)
* [Wilddog FAQ](https://z.wilddog.com/faq/qa)


## License
MIT
http://wilddog.mit-license.org/

## 感谢 Thanks

lib-ios-wilddogui is built on and with the aid of several projects. We would like to thank the following projects for helping us achieve our goals:

Open Source:

* [firebaseUI](https://github.com/firebase/firebaseui-ios) FirebaseUI powered by Firebase
