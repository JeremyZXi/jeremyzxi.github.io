# AHP IMMC2024


## Judging Matrix

|  | Household Members' Pet Allergies | Number of Household Members | Average Living Space per Person | Average Disposable Income per Person | Pet Attitude | Previous Pet Experience | Existence of Junior and Senior Household Members | Self-Assessed Overall Health Condition | Final Education Level |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Household Members' Pet Allergies | 1 | 4 | 4 | 4 | 2 | 3 | 3 | 3 | 4 |
| Number of Household Members | 1/4 | 1 | 1/2 | 1/3 | 1/4 | 1/2 | 1/2 | 3 | 2 |
| Average Living Space per Person | 1/4 | 2 | 1 | 1 | 1/2 | 1 | 1 | 2 | 2 |
| Average Disposable Income per Person | 1/4 | 3 | 1 | 1 | 1/3 | 1 | 1 | 2 | 3 |
| Pet Attitude | 1/2 | 4 | 2 | 3 | 1 | 3 | 2 | 3 | 3 |
| Previous Pet Experience | 1/3 | 2 | 1 | 1 | 1/3 | 1 | 2 | 2 | 1 |
| Existence of Junior and Senior Household Members | 1/3 | 2 | 1 | 1 | 1/2 | 1/2 | 1 | 1 | 2 |
| Self-Assessed Overall Health Condition | 1/3 | 1/3 | 1/2 | 1/2 | 1/3 | 1/2 | 1 | 1 | 1/3 |
| Final Education Level | 1/4 | 1/2 | 1/2 | 1/3 | 1/3 | 1 | 1/2 | 3 | 1 |

## Weights

| Params | Weight |
| --- | --- |
| Household Members' Pet Allergies ($a$)| 0.26884598 |
| Number of Household Members ($n$)| 0.06366679 |
| Average Living Space per Person ($s$)| 0.09101158 |
| Average Disposable Income per Person ($d$)| 0.1006127 |
| Pet Attitude ($p_{a}$)| 0.19073045 |
| Previous Pet Experience ($e$)| 0.09242143 |
| Existence of Junior and Senior Household Members ($m$) | 0.08347651 |
| Self-Assessed Overall Health Condition ($h$)| 0.04871114 |
| Final Education Level ($e_{l}$)| 0.06052343 |

Normalize the data with min-max normalization:

$$
x_{scaled} = \frac{x-x_{min}}{x_{max}-x_{min}}
$$

Household Members' Pet Allergies: $a$

Number of Household Members: $n$

Average Living Space per Person:$s$

Average Disposable Income per Person: $d$

Pet Attitude:$p_{a}$

Previous Pet Experience:$e$

Existence of Junior and Senior Household Members:$m$

Self-Assessed Overall Health Condition:$h$

Final Education Level:$e_{l}$