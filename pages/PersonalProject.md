---
layout: page
title: Personal Project
permalink: /Personal_Project/
feature-img: "assets/img/portfolio/MyTello.jpg"
tags: [Page,MYP Personal Project]
---
# Drone ✖️ AI
### Goal
To acquire expertise in machine learning for drone image processing and flight control, I intend to construct a drone that
incorporates image processing capabilities, such as posture recognition, as well as the fundamental components of flight
control.

I hope to acquire both foundational and advanced knowledge in machine learning as well as practical experience in
constructing a drone. I aim to employ AI to tackle real-life problems, enhancing the convenience of people's daily lives.
Additionally, this project will equip me with invaluable expertise that can aid me in pursuing further ventures related to AI,
engineering, or computer science.
### Product/Outcome
**Product:**
The proposed concept involves an AI model that has been trained to identify specific postures, gestures, or movements of
humans. This model will be integrated into a drone, enabling it to utilize the model for flight control and other
functionalities.

**Specifications:**
- **Data-collection:** collection sufficient amount of positive and negative data for the model
- **Programm:** A program that works
- **AI model:** A model that can recongonize motions and posture of human
- **Drone:** A drone that do certain operation with the output of the AI model
### Process Journal
Learning:
[Intro to Machine Learning](https://jeremyzxi.github.io/2023/09/05/PP-process_journal.html).  [The Mathematics Behind Neural Networks
](https://jeremyzxi.github.io/2023/07/05/PP-process_journal2.html).  [Movement Detection](https://jeremyzxi.github.io/2023/07/15/PP-Process_journal3.html).  [Body Landmarks Detection
](https://jeremyzxi.github.io/2023/07/20/PP-process_journal4.html)<br>
Product-Data Collection & Approach with CNN:
[2023/08/04](https://jeremyzxi.github.io/2023/08/04/Product-Process-Journal.html)<br>
Product-Approach with RNN:
[2023/10/01](https://jeremyzxi.github.io/2023/10/01/Product-Process-Journal.html)<br>
Product-Model deployment(RNN):
[2023/10/17](https://jeremyzxi.github.io/2023/10/17/Product-Process_Journal.html)<br>
Product-Drone+Model:
[2023/10/22](https://jeremyzxi.github.io/2023/10/22/Produc_Process-Journal.html)
### Update March 19 2024
![MeInPPExh]({{ "assets/img/MeInPPExh.png" | relative_url}})
*Me in Personal Project Exhibition Source:The cover of [an article](https://www.keystoneacademy.cn/index.php?s=/Cn/Index/pageView/catid/58/id/138.html) on my school's website*
Frankly speaking, I feel like I failed this entire project as my model basically not work in most of the time...despite the fact that it score around $$0.95$$ on the validation set. This is obviously a sign of overfitting as my dataset is to tiny(no more than 10 minutes of video feed). Furthermore, I have done barely no hyper-parameters tuning. In fact, before I start doing mathematical modeling contest, all I knew about hyper parameters are jsut the existence of them. I did change the epochs and some params of each dense layer, but that was pure guessing. That being said, maybe my solution of the problem is just not a good way of doing it(RNN is not specialized for CV, while my why of processing data could be problematic).