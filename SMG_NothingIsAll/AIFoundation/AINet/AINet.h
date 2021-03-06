//
//  AINet.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/9/17.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AIModel,AINode,AIImvAlgsModel,AIPointer,AIKVPointer,AIPort,AIFrontOrderNode,AINetAbsFoNode,AIAbsCMVNode,AIAlgNode,AIAbsAlgNode;
@interface AINet : NSObject

+(AINet*) sharedInstance;

//MARK:===============================================================
//MARK:                     < index >
//MARK:===============================================================
-(NSMutableArray*) getAlgsArr:(NSObject*)algsModel;  //装箱 (algsModel to indexPointerArr);
-(AIPointer*) getNetDataPointerWithData:(NSNumber*)data algsType:(NSString*)algsType dataSource:(NSString*)dataSource;//单data装箱


//MARK:===============================================================
//MARK:                     < reference >
//MARK:===============================================================

/**
 *  MARK:--------------------引用序列--------------------
 *  @param indexPointer : value地址
 *  @param target_p : 引用者地址(如:xxNode.pointer)
 *
 *  注: 暂不支持output;
 */
-(void) setNetReference:(AIKVPointer*)indexPointer target_p:(AIKVPointer*)target_p difValue:(int)difValue;

//获取算法单结果的第二序列联想;
-(NSArray*) getNetReference:(AIKVPointer*)pointer limit:(NSInteger)limit;


//MARK:===============================================================
//MARK:                     < cmv >
//MARK:===============================================================
-(AIFrontOrderNode*) createCMV:(NSArray*)imvAlgsArr order:(NSArray*)order;


//MARK:===============================================================
//MARK:                     < absFo >
//MARK:===============================================================
-(AINetAbsFoNode*) createAbsFo_Outside:(AIFoNodeBase*)foA foB:(AIFoNodeBase*)foB orderSames:(NSArray*)orderSames;
-(AINetAbsFoNode*) createAbsFo_Inner:(AIFoNodeBase*)conFo orderSames:(NSArray*)orderSames;


//MARK:===============================================================
//MARK:                     < directionReference >
//MARK:===============================================================
-(AIPort*) getNetNodePointersFromDirectionReference_Single:(NSString*)mvAlgsType direction:(MVDirection)direction;
-(NSArray*) getNetNodePointersFromDirectionReference:(NSString*)mvAlgsType direction:(MVDirection)direction limit:(int)limit;
-(NSArray*) getNetNodePointersFromDirectionReference:(NSString*)mvAlgsType direction:(MVDirection)direction filter:(NSArray*(^)(NSArray*))filter;

/**
 *  MARK:--------------------cmvNode或absCMVNode构建时,报告directionReference--------------------
 *  @param difStrong : mv的迫切度越高,越强;
 *  @param direction : 方向(delta的正负)
 */
-(void) setNetNodePointerToDirectionReference:(AIKVPointer*)cmvNode_p mvAlgsType:(NSString*)mvAlgsType direction:(MVDirection)direction difStrong:(NSInteger)difStrong;


//MARK:===============================================================
//MARK:                     < AINetOutputIndex >
//MARK:===============================================================

//小脑索引
-(AIKVPointer*) getOutputIndex:(NSString*)dataSource outputObj:(NSNumber*)outputObj;


//MARK:===============================================================
//MARK:                     < absCmv >
//MARK:===============================================================
-(AIAbsCMVNode*) createAbsCMVNode_Outside:(AIKVPointer*)absFo_p aMv_p:(AIKVPointer*)aMv_p bMv_p:(AIKVPointer*)bMv_p;
-(AIAbsCMVNode*) createAbsCMVNode_Inner:(AIKVPointer*)absFo_p conMv_p:(AIKVPointer*)conMv_p;


//MARK:===============================================================
//MARK:                     < algNode >
//MARK:===============================================================

/**
 *  MARK:--------------------创建祖母节点--------------------
 *  将微信息组,转换成祖母节点;
 *  需要对祖母节点指定当前的isOut状态; (思维控制器知道它是行为还是认知)
 *  @result notnull
 */
-(AIAlgNode*) createAlgNode:(NSArray*)algsArr isOut:(BOOL)isOut isMem:(BOOL)isMem;


/**
 *  MARK:--------------------构建抽象祖母--------------------
 *  1. 内类比调用 & 外类比调用 (存硬盘)
 *  2. thinkIn调用 (存内存)
 */
-(AIAbsAlgNode*) createAbsAlgNode:(NSArray*)value_ps conAlgs:(NSArray*)conAlgs isMem:(BOOL)isMem;

//获取绝对匹配到value_ps的algNode (祖母引用联想的方式去重)
-(AIAlgNodeBase*) getAbsoluteMatchingAlgNodeWithValueP:(AIPointer*)value_p;
-(AIAlgNodeBase*) getAbsoluteMatchingAlgNodeWithValuePs:(NSArray*)value_ps exceptAlg_p:(AIPointer*)exceptAlg_p;

@end


