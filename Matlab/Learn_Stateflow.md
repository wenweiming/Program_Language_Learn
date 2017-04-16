# Stateflow ���

Stateflow��һ����ڷ��滷������������ܹ�ͨ��`state machines`��`flow charts`������ģ�ͺͶ��������������߼��������з��档

# ����Event-Drivenϵͳģ�͵Ļ�������
## ����ϵͳ����
�ڽ���Stateflowͼ֮ǰ��Ҫ��ȷ��ϵͳ�����ԡ�ͨ��������������ϵͳ�����Ƿ����ܵ���
* What are your interfaces?
 * ���ϵͳ�ᱻ��Щ�¼�������What are the event triggers to which your system reacts?��
 * ���ϵͳ������������Щ��what are the inputs to your system?��
 * ���ϵͳ�����������Щ��what are the outputs from your system?��
* Does your system have any operating modes? 
 * ϵͳ�в�ͬ����ģʽ����Щ����ģʽ����Щ����if the answer is yes, what are the operating modes?��
 * ������ģʽ��ת�����в��еĲ���ģʽ�𣿣�Between which modes can you transition? Are there any operating modes that run in parallel?)
 
������ϵͳû�в���ģʽ������һ��`stateless`��ϵͳ�� 

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
