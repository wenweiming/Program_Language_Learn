# Stateflow 简介

Stateflow是一款基于仿真环境，这个环境能够通过`state machines`和`flow charts`来建立模型和对联合且连续的逻辑决定进行仿真。

# 建立Event-Driven系统模型的基本方法
## 分析系统属性
在建立Stateflow图之前，要先确定系统的属性。通过下面的问题检查对系统属性是否考虑周到。
* What are your interfaces?
 * 你的系统会被哪些事件触发（What are the event triggers to which your system reacts?）
 * 你的系统的输入量有哪些（what are the inputs to your system?）
 * 你的系统的输出量有哪些（what are the outputs from your system?）
* Does your system have any operating modes? 
 * 系统有不同操作模式，这些操作模式是哪些？（if the answer is yes, what are the operating modes?）
 * 你能在模式间转变吗？有并行的操作模式吗？（Between which modes can you transition? Are there any operating modes that run in parallel?)
 
如果你的系统没有操作模式，就是一个`stateless`的系统。 

## States
* State Hierarchy
* State Decomposition
 * Exclusive(OR) State Decomposition
 * Parallel(AND) State Decomposition
* State Labels with the following general format:
 ```
 name/
 entry:entry actions
 during:during actions
 exit:exit actions
 on event_name: on event_name actions
 bind:events
 ```

## Transitions 
* Transition Hierarchy:
A transition's hierachy is described in terms of the transition's parent, source, and destination. The parent is the lowest level that contains the source and destination of the transition. 
* Transition Label Notation
Transition labels have the following general format:
```
event[condition]{condition_action}/transition_action
```
 * Event Trigger. 
 Specifies an event that causes the transition to be taken, provided the condition, if specified, is true. Specifying an event is optional. The absence of an event indicates that the transition is taken upon the occurrence of any event. Specify multiple events using the OR logical operator (|).
