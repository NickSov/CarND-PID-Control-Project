# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## PID Overview

The PID algorithm is simple and highly used in industry. It finds particular use in the process control industry in which certain values need to be reached and kept within a tight range. The controller works by utilizing three corrective responses:

1. Proportional control

  Proportionally reacts to the error in the system; if the error is big, the gain will be big. The issue with proportional only is that it never hits the target because it consistently overshoots. Proportional control also seems to oscillate with increasing amplitude until the oscillations are so great that they lead to disastrous. outcomes.

2. Integral based control

  Integral control contains the history of the error over time. The integral component of error accumulates as long as error is present; therefore, this term helps to narrow in on the target and reduce the error in the system.

3. Derivative based control

  Derivative control helps dampen the system since it accounts for how quickly the error changes. Large rates of change in error, result in a large derivative error component.

A simple PID control loop is shown below, with the include code components for the P, I, and D terms:

<img src="" width="750">


## PID Gain Parameter Effects

The various parameters, more or less, had the effects described above for each of the control methods. More specifically, if the proportional gain was increased, the car had more drastic oscillatory movements earlier on. If the proportional gain was low, the movements would less in the begin, but eventually they increased and caused the vehicle to escape the road. The integral term seemed to help with the oscillation but it actually did not eliminate it, this was because the ratio of parameters is so important. It was noticeable that a large term for the integral actually caused more "brutal" reactions because there was so much error compounding in the beginning that it quickly forced the vehicle off of the road. Lastly, the derivative term seemed to also create for oscillations, just smaller ones. The problem with the derivative was that it would never completely eliminate the oscillations, just minimize them.  

## Tuning Parameter Selection

Parameter tuning was tedious in the beginning as I tried a guess and check method. After some time, I realized that the controller was performing poorly and that I could endless try to make it better. Next I looked into the literature to see what methods exist for PID controller tuning. I settled on the second fastest method: **Ziegler-Nichols' Tuning**.

Ziegler-Nichols actually consists of two methods, I chose the simpler. The steps I took were as follows:

1. Incrementally increase the *Kp* gain while keeping the rest of the gains at zero
2. When the vehicle begins to oscillate, determine the period *T*.
3. Using the period and the gain value, utilize the empirical Ziegler-Nichols table below

**Recorded Data for Period Determination**

<img src="" width="750">

**Ziegler-Nichols Control Parameters**

<img src="" width="750">

**Calculated Gains**

<img src="" width="750">
