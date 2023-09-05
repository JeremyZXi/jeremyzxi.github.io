---
layout: post
title: >
    Keystone Summer AI Program
tags: [Test, AI, Keystone]
---
# **Machine Learning**
## *Let computers to learn and acquire laws from data*

<br>


## ***Python Libary***

```Python
import pandas #data analysis
import numpy #math
import sklearn #machine learning
import matplotlib #plotting
import jieba #split Chinese sentences
```


## ***Machine learning models***
### 电能预测
<br>

## <font color = "#2E2EFF">*Linear Regression*

<br>

### 监督学习 回归模型 用于连续数据



```python
import matplotlib.pyplot as plt
%matplotlib inline
import numpy as np
import pandas as pd 


# 使用pandas的read_csv读取数据
data = pd.read_csv("ccpp.csv")
# 显示前5行数据
data.head(5)
# duplicated()检查重复值
# value_counts()计算表格中有多少不同值
data.duplicated().value_counts()
# 删除重复值
data = data.drop_duplicates()
# 通过.isnull().any()能判断表格中的缺失值。
data.isnull().any()

from sklearn.model_selection import train_test_split

# 数据集拆分为训练集和测试集 

X_train, X_test, y_train, y_test = train_test_split(data[["AT", "V", "AP", "RH"]], 
                                                    data["PE"], 
                                                    test_size=0.3)
                                                
# 模型训练
from sklearn.linear_model import LinearRegression

linreg = LinearRegression()

linreg.fit(X_train, y_train)

# 模型测试
linreg.score(X_test,y_test)
# 模型预测
y_pred = linreg.predict(X_test)
# 绘图
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline
x, y = pd.Series(y_test, name="真实值"), pd.Series(y_pred, name="预测值")

sns.regplot(x = x,y = y)

# 评价指标

from sklearn.metrics import mean_squared_error
# 计算预测值和真实值的均方误差
mean_squared_error(y_test, y_pred)
from sklearn.metrics import mean_absolute_error
# 计算预测值和真实值的平均绝对误差
mean_absolute_error(y_test, y_pred)
# 中位数绝对误差
from sklearn.metrics import median_absolute_error
# 计算预测值和真实值的中位数绝对误差
mean_absolute_error(y_test, y_pred)
# 决定系数
from sklearn.metrics import r2_score
# 计算预测值和真实值的决定系数
r2_score(y_test, y_pred)
```
<br>

>* <font color = "#000000">线性回归模型:
>𝑦 = 𝜔1𝑥1 + 𝜔2𝑥2 + ⋯ + 𝜔𝑛𝑥𝑛 + 𝜔0

>* 损失函数：
>
>|𝑦(𝑖) − 𝑦(𝑖)|（前一个y是第i个训练样本的真实数据，后一个>y是第i个训练样本的预测数据
>
>(𝑦(𝑖) − 𝑦(𝑖))^2（前一个y是第i个训练样本的真实数据，后一>个y是第i个训练样本的预测数据


