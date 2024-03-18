---
layout: post
title: >
    2024 IMMC Greater China
tags: [Test, Mathematical modeling, Reflection]
excerpt_separator: <!--more-->
---
Better than last time...?
<!--more-->
Honestly, I feel like the problem this time was way too much easier compared to the one in HiMCM 2023, possibly because this was just the first round. After all, Integrodifference Equations were "a bit" tooooo early for high school students. Linear programming, on the other hand, is not much easier, but at least the coding part doesn't require too much understanding with respect to the core math part, thanks to the MATLAB optimization toolbox!!!
## What have we done
### Problem chosing
I chosee this one after reading both problems mainly because the following reasons:
- this problem doesn't seem to need a lot of data, all data required were provided. 
- The logic flow of this problem is clearer(at least for me)
- It seems fun...come on, who would reject "auto chicken counter"
### Our work
We have a clear workflow this time. We start from simple method and developed it as we go.
1. We kick of by consider only the price each agent paied.
![AliceAndBobSPP]({{ "assets/img/IMMC_SPP.png" | relative_url}})
2. We then try to make it "fair" by introducing Adjusted Winner Procedure
![AliceAndBobAWP]({{ "assets/img/IMMC_AWP.png" | relative_url}})
3. To make it fine, we ended up using linear and nonlinear programming. We normalized each agent's price to calculate the "utility"
![All]({{ "assets/img/IMMC_NLPAll.png" | relative_url}})
## Overall

This round was way better than last time; at least there were no confusing equations that took up 2 lines. We only have 3 people this time so I ended up typing all those formulas. Adimittedly, it was a bit tedious for me, but I guess I'm the only one capable of doing it in our team...so yeah.
*Item
- I am not sure if it was a "me problem" or not...All of our team memebers were familiar with each other; that being said, we still somehow messed up with the communication part. 
    >O.S. I finally realized that ATL skills are actually very important :)

    One issue I encountered was that, at the very beginning, I came up with a simple framework for our model. Since Latex was so annoying and time-consuming, I wrote all things down and asked one of my teammates to organize them on the tex file. However, what she did was OCR my entire notes with ChatGPT or something and paste them on... I am somehow responsible for this matter, as I should have just told her what to do instead of just snapping my notes.

- We urgently need a sharing platform to keep our work, diagrams, notes, and codes. The problem here is that once we divided our work, each of us just went to work separately. After an hour, when we meet again to check our progress, it turns out that somebody has either done literally nothing or has no idea what they are doing. We don't really need Git or Gist, as I am basically the only coder in the team, but we do need to keep track of all our other work. Github could be a good option, but preferably a more user-friendly one (PowerPoint?).
## About myself
- My scripts are messy; though, my programming ability improved (perhaps because the MATLAB optimization toolbox was sooooo user-friendly that I feel like I am using a TI84 pro max ++++ that offers me 30 days free trial).
- Communication could be, perhaps, one of my problems. For some reason, I am always struggling when communicating with one of my teammates.
- More organized: My folder organization was much better. I am able to name them properly and store them in the correct place.
![Folder]({{ "assets/img/IMMC_OrganizedFolder.png" | relative_url}})

    The "V+number" prefix was good; especially when I don't know how to use Git. 