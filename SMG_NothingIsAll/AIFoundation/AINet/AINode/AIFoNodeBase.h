//
//  AIFoNodeBase.h
//  SMG_NothingIsAll
//
//  Created by jiaxiaogang on 2018/10/19.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------FoNode基类--------------------
 *  1. 是frontOrderNode和absNode的基类;
 */
@interface AIFoNodeBase : AINodeBase

@property (strong, nonatomic) AIKVPointer *cmvNode_p;        //cmvNode_p结果;
@property (strong, nonatomic) NSMutableArray *orders_kvp;       //在imv前发生的noMV的algs数据序列;(前因序列)(使用kvp而不是port的原因是cmvModel的强度不变:参考n12p16)

@end
