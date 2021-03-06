//
//  GridViewProtocols.h
//  Everycam
//
//  Created by Benjamin Maer on 12/5/12.
//  Copyright (c) 2012 Resplendent G.P. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GridView;


@protocol GridViewDataSource <NSObject>

-(NSUInteger)gridViewNumberOfTiles:(GridView*)gridView;

-(UIView*)gridView:(GridView*)gridView newTileForIndex:(NSUInteger)index;
-(void)gridView:(GridView*)gridView reloadTile:(UIView*)tile atIndex:(NSUInteger)index;

@optional
-(void)gridView:(GridView*)gridView prepareTileForRemoval:(UIView*)view;

@end

typedef enum{
    GridViewScrollDelegateDirectionUp,
    GridViewScrollDelegateDirectionDown
}GridViewScrollDelegateDirection;

@protocol GridViewScrollDelegate <NSObject>

-(void)gridView:(GridView*)gridView didScrollWithDirection:(GridViewScrollDelegateDirection)direction;

@end


@protocol GridViewDataSourceSelectionDelegate <NSObject>

-(void)gridView:(GridView*)gridView didSelectTileAtIndex:(NSUInteger)index;

@end



@protocol GridViewPullToLoad <NSObject>

-(void)gridViewPullToReload:(GridView*)gridView;
-(void)gridViewPullToLoadMore:(GridView*)gridView;

@end