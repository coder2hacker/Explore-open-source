#%%
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
import pandas as pd
import numpy as np
import sklearn
import sys
import os

DeprecationWarning('ignore')
os.chdir('D:/machine_learning/titanic')

#%%
df=pd.read_csv('train.csv')

#%%
df

#%%
df.head()

#%%
df.sample(12)

#%%
df.describe()

#%%
df.isnull().sum()

#%%
import seaborn as sns
sns.distplot(df.Fare.dropna())

#%%
sample=df.sample(40)
sample.describe()

#%%
train, test= train_test_split(df, test_size=0.2, random_state=12)


#%%
train.shape

#%%



#%%
x=[1,2,3,4,5,15]
total=0
for i in x:
    total+=i
total

#%%
def train_test(df):
    length=len(df)
    train=df.iloc[:712,:]
    test=df.iloc[712:,]
    return train, test

#%%
train.head()

#%%
df['Ticket']
#%%
df.iloc[:,0:9]

#%%
df.loc[:,['Age','Parch']]

#%%
train.isnull().sum()

#%%
mean_age=train.Age.mean()

#%%
# train['Age']=train['Age'].fillna(mean_age, inplace=True)
df=train.copy()
#%%
def fill_age(df):
    mean=29.67
    df['Age'].fillna(mean, inplace=True)
    return df

def fill_Embarked(df):
    df.Embarked.fillna('S', inplace=True)
    return df

def label_encode(df):
    from sklearn.preprocessing import LabelEncoder
    label=LabelEncoder()
    df['Sex']=label.fit_transform(df['Sex'])
    #transform will convert string to integer
    df['Embarked']=label.fit_transform(df['Embarked'])
    return df

def encode_feature(df):
    df=fill_age(df)
    df=fill_Embarked(df)
    df= label_encode(df)
    return df

train=encode_feature(train)
test= encode_feature(test)
#%%
def x_and_y(df):
    x = df.drop(["Survived",'PassengerId','Cabin','Name','Ticket'], axis=1)
    y = df['Survived']
    return x, y

x_train, y_train = x_and_y(train)
x_test, y_test= x_and_y(test)


#%%
log_model= LogisticRegression()
log_model.fit(x_train, y_train)
#fit will find pattern in the csv file 
prediction= log_model.predict(x_train)
score= accuracy_score(y_train, prediction)
#accuracy_score will tell the accuracy of the data set
print(score)

#%%
from scipy import stats
stats.pearsonr(train['Fare'],train['Age'])

#%%
import seaborn as sns 
sns.scatterplot(train['Age'],train['Fare']) 

#%%
x_train.columns

#%%
test=pd.read_csv('test.csv')
test=encode_feature(test)

#%%
test.head()

#%%
test=test.drop(['PassengerId', 'Ticket', 'Cabin', 'Name'],axis=1)

#%%
test.columns

#%%
test.isnull().sum()

#%%
mean_Fare=test.Fare.mean()

#%%
mean_Fare

#%%
def fill_age(test):
    mean=35.62
    test['Fare'].fillna(mean, inplace=True)
    return test
test=fill_age(test)
test

#%%
test.isnull().sum()

#%%
prediction_test= log_model.predict(test)

#%%
prediction_test

#%%
print(prediction_test)

#%%
from sklearn.metrics import roc_curve
prob=log_model.predict_proba(x_train)
prob
#%%
import seaborn as sns


#%%
