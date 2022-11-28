# run linear regression on train3.csv and use pca to drop variables that have less than 0.1 variance

import pandas as pd
import numpy as np
from sklearn import linear_model
from sklearn.decomposition import PCA
from sklearn.metrics import mean_squared_error, r2_score

df = pd.read_csv("train3.csv")

# drop non important vairables
pca = PCA(n_components=0.1)
pca.fit(df)
df = df[df.columns[pca.get_support(indices=True)]]

# run lasso regression on the data
X = df.drop(["y"], axis=1)
y = df["y"]
regr = linear_model.Lasso(alpha=0.1)
regr.fit(X, y)
y_pred = regr.predict(X)

# show an equaiton of the regression
print("Coefficients: ", regr.coef_)
print("Intercept: ", regr.intercept_)
print("Mean squared error: %.2f" % mean_squared_error(y, y_pred))
print("Coefficient of determination: %.2f" % r2_score(y, y_pred))
print("Intercept: ", regr.intercept_)
print("Mean squared error: %.2f" % mean_squared_error(y, y_pred))
print("Coefficient of determination: %.2f" % r2_score(y, y_pred))
# print("Equation: y = ", regr.intercept_, " + ", regr.coef_[0], "*x1 + ", regr.coef_[1], "*x2 + ", regr.coef_[2], "*x3 + ", regr.coef_[3], "*x4 + ", regr.coef_[4], "*x5 + ", regr.coef_[5], "*x6 + ", regr.coef_[6], "*x7 + ", regr.coef_[7], "*x8 + ", regr.coef_[8], "*x9 + ", regr.coef_[9], "*x10 + ", regr.coef_[10], "*x11 + ", regr.coef_[11], "*x12 + ", regr.coef_[12], "*x13 + ", regr.coef_[13], "*x14 + ", regr.coef_[14], "*x15 + ", regr.coef_[15], "*x16 + ", regr.coef_[16], "*x17 + ", regr.coef_[17], "*x18 + ", regr.coef_[18], "*x19 + ", regr.coef_[19], "*x20 + ", regr.coef_[20], "*x21 + ", regr.coef_[21], "*x22 + ", regr.coef_[22], "*x23 + ", regr.coef_[23], "*x24 + ", regr.coef_[24], "*x25 + ", regr.coef_[25], "*x26 + ", regr.coef_[26], "*x27 + ", regr.coef_[27], "*x28 + ", regr.coef_[28], "*x29 + ", regr.coef_[29], "*x30 + ", regr.coef_[30], "*x31 + ", regr.coef_[31], "*x32 + ", regr.coef_[32], "*x33 + ", regr.coef_[33], "*x34 + ", regr.coef_[34], "*x35 + ", regr.co
