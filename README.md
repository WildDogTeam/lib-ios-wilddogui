# WilddogUI for iOS — UI Bindings for Wilddog
WilddogUI是一个iOS开源库，允许您快速连接常用UI元素到[Wilddog](https://www.wilddog.com/?utm_source=wilddogui-ios) 数据库进行数据存储，允许视图随着更改实时更新，并为常见任务提供简单的界面，如显示列表或集合项目。

## Getting Started with Wilddog 
WilddogUI需要Wilddog来存储本地数据。您可以在这里注册一个[免费帐户](https://www.wilddog.com/my-account/signup).

## WilddogUI for iOS Quickstart

这是一个关于如何使用WilddogUI的核心功能搭配Wilddog来加速iOS开发。 WilddogUI包括以下功能:

Class  | Description
------------- | -------------
WilddogTableViewDataSource | 数据源将Wilddog查询绑定到UITableView
WilddogCollectionViewDataSource | 将Wilddog查询绑定到UICollectionView的数据源
WilddogArray | 保持数组与Wilddog查询同步
WilddogDataSource | 通用超类，用于创建自定义数据源

### WilddogTableViewDataSource


`WilddogTableViewDataSource`实现`UITableViewDataSource`协议来自动使用Wilddog作为你的`UITableView`的数据源。

#### Objective-C
```objective-c
YourViewController.h
...
@property (strong, nonatomic) WDGSyncReference *wilddogRef;
@property (strong, nonatomic) WilddogTableViewDataSource *dataSource;
```

```objective-c
YourViewController.m
...
//初始化 WDGApp
WDGOptions *option = [[WDGOptions alloc] initWithSyncURL:@"https://<YOUR-WILDDOG-APP>.wilddogio.com"];
[WDGApp configureWithOptions:option];
//获取一个指向根节点的 WDGSyncReference 实例
self.wilddogRef = [[WDGSync sync] reference];
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:self.wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDGDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.textLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```


### WilddogCollectionViewDataSource

`WilddogCollectionViewDataSource`实现`UICollectionViewDataSource`协议来自动使用Wilddog作为`UICollectionView`的数据源。

#### Objective-C
```objective-c
YourViewController.h
...
@property (strong, nonatomic) WDGSyncReference *wilddogRef;
@property (strong, nonatomic) WilddogCollectionViewDataSource *dataSource;
```

```objective-c
YourViewController.m
...
//初始化 WDGApp
WDGOptions *option = [[WDGOptions alloc] initWithSyncURL:@"https://<YOUR-WILDDOG-APP>.wilddogio.com"];
[WDGApp configureWithOptions:option];
//获取一个指向根节点的 WDGSyncReference 实例
self.wilddogRef = [[WDGSync sync] reference];
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:self.wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDGDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.backgroundColor = [UIColor blueColor];
}];

[self.collectionView setDataSource:self.dataSource];
```


## Customizing your UITableView or UICollectionView

您可以使用`WilddogTableViewDataSource`或`WilddogCollectionViewDataSource`这几种方式创建自定义UITableViews或UICollectionViews。有关如何创建自定义UITableView的更多信息，请查看以下[TutsPlus教程](http://code.tutsplus.com/tutorials/ios-sdk-crafting-custom-uitableview-cells--mobile-15702).有关如何创建自定义UICollectionViews的更多信息，特别是如何实现UICollectionViewLayout，请查看以下教程关于Ray Wenderlich在[Objective-C](http://www.raywenderlich.com/22324/beginning-uicollectionview-in-ios-6-part-12).

### Using the Default UI*ViewCell Implementation


您可以使用默认的“UITableViewCell”或“UICollectionViewCell”实现快速启动和运行。对于`UITableViewCell`，这允许`cell.textLabel`和`cell.detailTextLabel`被直接使用。对于`UICollectionViewCell`s，为了它是有用的你将不得不添加子视图到contentView。

#### Objective-C UITableView and UICollectionView with Default UI*ViewCell
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDGDataSnapshot *snap) {
  // Populate cell as you see fit, like as below
  cell.textLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectioneViewDataSource alloc] initWithRef:wilddogRef cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDGDataSnapshot *snap) {
  // Populate cell as you see fit by adding subviews as appropriate
  [cell.contentView addSubview:customView];
}];

[self.collectionView setDataSource:self.dataSource];
```

### Using Storyboards and Prototype Cells

创建一个具有`UITableViewController`，`UICollectionViewController`或`UIViewController`与`UITableView`或`UICollectionView`的故事板。将原型单元拖到`UITableView`或`UICollectionView`，并给它一个自定义重用标识符，它匹配在实例化`Wilddog * ViewDataSource`时使用的重用标识符。当使用原型单元格时，确保使用`prototypeReuseIdentifier`而不是`cellReuseIdentifier`。


将其他属性拖动到单元格上，并将它们与“UITableViewCell”或“UICollectionViewCell”子类的属性相关联。代码示例与上述类似。

### Using a Custom Subclass of UI*ViewCell

创建一个自定义子类`UITableViewCell`或`UICollectionViewCell`，有或没有XIB文件,确保实例化`-initWithStyle：reuseIdentifier：`来实例化一个`UITableViewCell`或`-initWithFrame：`来实例化一个`UICollectionViewCell`。然后可以将自定义类挂接到WilddogTableViewDataSource的实现。

#### Objective-C UITableView and UICollectionView with Custom Subclasses of UI*ViewCell
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef cellClass:[YourCustomClass class] cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(YourCustomClass *cell, WDGDataSnapshot *snap) {
  // Populate custom cell as you see fit, like as below
  cell.yourCustomLabel.text = snap.key;
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectioneViewDataSource alloc] initWithRef:wilddogRef cellClass:[YourCustomClass class] cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.CollectionView];

[self.dataSource populateCellWithBlock:^(YourCustomClass *cell, WDGDataSnapshot *snap) {
  // Populate cell as you see fit
  cell.customView = customView;
}];

[self.collectionView setDataSource:self.dataSource];
```

### Using a Custom XIB

创建自定义XIB文件并将其挂接到原型单元格。然后可以像任何其他UITableViewCell一样使用它，使用自定义标签或使用与XIB关联的自定义类。

#### Objective-C UITableView and UICollectionView with Custom XIB
```objective-c
self.dataSource = [[WilddogTableViewDataSource alloc] initWithRef:wilddogRef nibNamed:@"<YOUR-XIB>" cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.tableView];

[self.dataSource populateCellWithBlock:^(UITableViewCell *cell, WDGDataSnapshot *snap) {
  // Use tags to populate custom properties, or use properties of a custom cell, if applicable
  UILabel *yourCustomLabel = (UILabel *)[cell.contentView viewWithTag:<YOUR-TAG>];
  yourCustomLabel.text = snap.key
}];

[self.tableView setDataSource:self.dataSource];
```

```objective-c
self.dataSource = [[WilddogCollectionViewDataSource alloc] initWithRef:wilddogRef nibNamed:@"<YOUR-XIB>" cellReuseIdentifier:@"<YOUR-REUSE-IDENTIFIER>" view:self.collectionView];

[self.dataSource populateCellWithBlock:^(UICollectionViewCell *cell, WDGDataSnapshot *snap) {
  // Use tags to populate custom properties, or use properties of a custom cell, if applicable
  UILabel *yourCustomLabel = (UILabel *)[cell.contentView viewWithTag:<YOUR-TAG>];
  yourCustomLabel.text = snap.key
}];

[self.tableView setDataSource:self.dataSource];
```

## Understanding WilddogUI's Internals


WilddogUI有几个构建块，开发人员应该了解，然后在WilddogUI上构建附加功能，包括一个同步数组`WilddogArray`和一个通用数据源超类`WilddogDataSource`，`WilddogTableViewDataSource`和`WilddogCollectionViewDataSource`或其他自定义视图类的子类。

### WilddogArray and the WilddogArrayDelegate Protocol


`WilddogArray`是将Wilddog Ref与数组连接的同步数组。它通过WilddogArrayDelegate协议显示Wilddog事件。通常建议开发人员不直接访问WilddogArray，而不通过自定义数据源路由它，虽然如果这是需要的，请查看下面的WilddogDataSource。

#### Objective-C
```objective-c
//初始化 WDGApp
WDGOptions *option = [[WDGOptions alloc] initWithSyncURL:@"https://<YOUR-WILDDOG-APP>.wilddogio.com"];
[WDGApp configureWithOptions:option];
//获取一个指向根节点的 WDGSyncReference 实例
WDGSyncReference  *wilddogRef = [[WDGSync sync] reference];
WilddogArray *array = [[WilddogArray alloc] initWithRef:wilddogRef];
```


### WilddogDataSource

WilddogDataSource通过提供公共信息（如数据源中的对象计数）以及通过要求子类根据视图实现WilddogArrayDelegate方法来充当通用数据源。此类不应被实例化，但在为View创建特定适配器时应该将其子类化。[WilddogTableViewDataSource](https://github.com/WildDogTeam/WilddogUI-iOS/blob/master/WilddogUI/Implementation/WilddogTableViewDataSource.m)和[WilddogCollectionViewDataSource](https://github.com/WildDogTeam/WilddogUI-iOS/blob/master/WilddogUI/Implementation/WilddogCollectionViewDataSource.m)就是这样的例子。 WilddogDataSource本质上是WilddogArray的包装器。
## 支持
如果在使用过程中有任何问题，请提 [issue](https://github.com/WildDogTeam/lib-ios-wilddogui/issues) ，我会在 Github 上给予帮助。

## 相关文档

* [Wilddog 概览](https://docs.wilddog.com/overview/index.html)
* [IOS SDK快速入门](https://docs.wilddog.com/overview/index.html)
* [IOS SDK API](https://docs.wilddog.com/api/sync/ios/WDGOptions.html)
* [下载页面](https://docs.wilddog.com/quickstart/sync/ios.html)
* [Wilddog FAQ](https://docs.wilddog.com/overview/index.html)


## License

[MIT](http://wilddog.mit-license.org/)

## 感谢 Thanks

lib-ios-wilddogui is built on and with the aid of several projects. We would like to thank the following projects for helping us achieve our goals:

Open Source:

* [firebaseUI](https://github.com/firebase/firebaseui-ios) FirebaseUI powered by Firebase
