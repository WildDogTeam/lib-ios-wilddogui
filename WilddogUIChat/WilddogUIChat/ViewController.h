//
//  ViewController.h
//  WilddogUIChat
//
//  Created by Mike Mcdonald on 8/20/15.
//  Copyright (c) 2015 Wilddog, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Wilddog/Wilddog.h>
#import <WilddogUI/WilddogUI.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITextFieldDelegate>

@property (strong, nonatomic) Wilddog *ref;
@property (strong, nonatomic) WilddogTableViewDataSource *dataSource;

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UITextField *inputTextField;

@end

