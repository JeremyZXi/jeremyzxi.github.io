---
layout: post
title: >
    Optimizing East 2 Thermos
tags: [Test, Mathematic modeling, notes]
excerpt_separator: <!--more-->
---
<!--more-->
# East 2 Thermos
The volume of a cylinder is given by:
$$Volume = \pi r^{2}h$$
The capacity of the thermos is $500 ml$ which is equavilent to 500cm^3(given by the puchasing information). 
Hence, the volume of the thermos is $500cm^3$
$$500= \pi r^{2}h$$
$$h=\frac{500}{\pi r^{2}}$$

The surface area of a cylinder is given by:$$2\pi r^{2}+2\pi rh$$
In case of a thermos, we ignore the lid part(没想好为什么要这么干)
- if with lid:

    surface area= $$2\pi rh_{1} + 2\pi rh_{2}+2\pi r^{2}$$

    但是盖子里面不能装水，因此我们无法确定应当给容积加上多少来考虑盖子
Consider $$h=\frac{500}{\pi r^{2}}$$, the surface area of a thermos can be written as:$$\pi r^{2}+2\pi r(\frac{500}{\pi r^{2}})$$
$$A(r)=\pi r^{2}+\frac{1000}{r}$$
$$A(r)=\pi r^{2}+1000r^{-1}$$
$$A(r)'=2\pi r+ -1 \times1000r^{-2}$$
$$A(r)'=2\pi r -\frac{1000}{r^{2}}$$

Let $A(r)'=0$:
$$0=2\pi r -\frac{1000}{r^{2}}$$
$$\frac{1000}{r^{2}}=2\pi r $$
$$1000=2\pi r^3$$
$$500=\pi r^3$$
$$r=\sqrt[3]{\frac{500}{\pi}}$$
# Single used plastic cup
$$r=\sqrt[3]{\frac{200}{\pi}}$$