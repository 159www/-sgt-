//
// Created by sgt on 2023/4/9.
//选择排序的实现
//

#include "sort.h"
/*
 * 目的：获取给定范围内整型数组的最小值下标
 * 参数1：整形数组名
 * 参数2：起始下标
 * 参数3：结尾下标
 *返回值：给定范围内整型数组的最小值下标
 */
int GetMinIndex(int Array[],int StartIndex,int EndIndex)
{
    int TempMin=Array[StartIndex];//假设起点元素为最小值元素
    int TempMinCopy=TempMin;//假定最小值元素的备份
    int TempMinIndex=StartIndex;//假设起点元素下标为最小值元素下标
    //遍历整个寻找最小值的区域
    for(int i=StartIndex+1;i<=EndIndex;i++)
    {
        //若存在元素值小于假设的最小元素
        if(Array[i]<TempMin)
        {
            //更新最小元素值和最小元素下标
            TempMin=Array[i];
            TempMinIndex=i;
        }
    }
    //若经过寻找后假定最小值与之前的备份一致表示首元素就是最小元素于是返回首元素下标
    if(TempMin==TempMinCopy)
    {
        return StartIndex;
    }
    else//首元素并非最小值返回更新的最小值下标
    {
        return TempMinIndex;
    }

}
/*
 * 目的：使用选择排序的方法对整型数组进行排序
 * 参数1：整型数组名
 * 参数2：整型数组长度
 * 返回值：无
 */
void sort(int Array[],int Len)
{
    int TempMinValueIndex;//保存最小元素下标
    int MinValue;//保存最小元素值
    int temp;//临时变量用于交换元素
    int j;//保存查找最小元素的起始下标
    for(int i=0;i<Len-1;i++)//Len-1次循环
    {
        /*
         * 每次循环会选出一个最小元素
         * 最后剩下的为最大值无需处理
         * 例子：
         * 4 1 3 2
         * 1、
         * 假定4为最小值，元素1至元素2的区域为无序区
         * 无序区域的最小值：最小值为1
         * 将假定最小值和无序区的最小值交换(因为无序区最小值小于假定最小值）
         * 得到序列：1 4 3 2
         * 2、
         * 假定4为最小值，元素3至元素2的区域为无序区
         * 无序区域的最小值：最小值为2
         * 将假定最小值和无序区的最小值交换(因为无序区最小值小于假定最小值）
         * 得到序列：1 2 3 4
         * 3、(由于没有检查序列是否有序故会执行步骤3)
         * 假定3为最小值，4元素的区域为无序区
         * 无序区域的最小值：最小值为4
         * 不做交换
         * 得到序列：1 2 3 4
         */
         MinValue=Array[i];//假设无序区前的第一个元素为最小元素并保存
         j=i+1;
         //寻找无序区中的最小元素下标并保存
         TempMinValueIndex=GetMinIndex(Array,j,Len-1);
         //若最小元素值小于或等于假定的最小元素值(为解决多个相同元素的情况)
         if((Array[TempMinValueIndex]<MinValue)||Array[TempMinValueIndex]==MinValue)
         {
             //若最小元素小于假定最小元素
             if(Array[TempMinValueIndex]<MinValue)
             {
                 //将最小元素和假定最小元素的位置交换
                 temp=Array[i];
                 Array[i]=Array[TempMinValueIndex];
                 Array[TempMinValueIndex]=temp;
             }//若最小元素等于假定最小元素
             else if(Array[TempMinValueIndex]==MinValue)
             {
                 //将最小元素和假定最小元素后一个元素的位置交换
                 temp=Array[i+1];
                 Array[i+1]=Array[TempMinValueIndex];
                 Array[TempMinValueIndex]=temp;
             }

         }
   }
}
