#import "BackgroundView.h"
#import "StatusItemView.h"

@class PanelController;

@protocol PanelControllerDelegate <NSObject>

@optional

- (StatusItemView *)statusItemViewForPanelController:(PanelController *)controller;

@end

#pragma mark -

@interface PanelController : NSWindowController <NSWindowDelegate>
{
    BOOL _hasActivePanel;
    __unsafe_unretained BackgroundView *_backgroundView;
    __unsafe_unretained id<PanelControllerDelegate> _delegate;
    __weak NSTextField *_localIPLabel;
    __weak NSTextField *_localNetmaskLabel;
    __weak NSButton *_CopyPublicIp;
}

@property (nonatomic, unsafe_unretained) IBOutlet BackgroundView *backgroundView;

@property (nonatomic) BOOL hasActivePanel;
@property (nonatomic, unsafe_unretained, readonly) id<PanelControllerDelegate> delegate;

- (id)initWithDelegate:(id<PanelControllerDelegate>)delegate;

- (void)openPanel;
- (void)closePanel;

@property (weak) IBOutlet NSTextField *localIPLabel;
@property (weak) IBOutlet NSTextField *localNetmaskLabel;
@property (weak) IBOutlet NSTextField *publicIP;
- (IBAction)copyPublicIP:(id)sender;
- (IBAction)CopyLocalIP:(id)sender;
- (IBAction)copyNetmask:(id)sender;

@end
