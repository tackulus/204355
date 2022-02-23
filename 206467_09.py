import numpy as np
import matplotlib.pyplot as plt
import cvxopt

def hyperplane(w,theta,xx):
    if w[1] == 0:
        y = xx
        if w[0] == 0: x = xx*0 + theta
        else:         x = (xx*0 + theta)/w[0]
    else:
        y = (-w[0]*xx + theta)/w[1]
        x = xx
    return [x,y]

Xm = np.array([[0,-1],[0,2]])
ym = [-1,-1]
x1, y1 = Xm[:,0], Xm[:,1]
plt.plot(x1,y1,'o',color='red')

Xp = np.array([[1,1]])
yp = [1]
x2, y2 = Xp[:,0], Xp[:,1]
plt.plot(x2,y2,'o',color='blue')

Xall = np.array(list(Xm) + list(Xp))
xx, yy = Xall[:,0], Xall[:,1]
aa, bb, cc, dd = [min(xx)-1, max(xx)+1, min(yy)-1, max(yy)+1]
plt.axis([aa,bb,cc,dd])
plt.grid(True)

from cvxopt import matrix 
from cvxopt import solvers 
X = Xall
y = np.array(ym+yp)
m,n = X.shape
y = y.reshape(-1,1) * 1.
X_dash = y * X
H = np.dot(X_dash , X_dash.T) * 1.

#Converting into cvxopt format
P = matrix(H)
q = matrix(-np.ones((m, 1)))
G = matrix(-np.eye(m))
h = matrix(np.zeros(m))
A = matrix(y.reshape(1, -1))
b = matrix(np.zeros(1))

solvers.options['show_progress'] = True

#Run solver
sol = solvers.qp(P, q, G, h, A, b)
mu = np.array(sol['x'])

### การบ้าน ให้หา w และ theta
w = -np.sum(mu.T * np.array(ym+yp) * X.T, axis=1)
theta = -0.5 * np.min(
    [-np.sum(
        (mu.T * np.array(ym+yp)) * np.sum(X * xp, axis=1)
    ) for xp in Xp]
) - 0.5 * np.max(
    [-np.sum(
        (mu.T * np.array(ym+yp)) * np.sum(X * xm, axis=1)
    ) for xm in Xm]
)

#Display results
print('mu = ',mu[mu > 1e-4])
print('w = ', w)
print('theta = ', theta)
xx = np.linspace(aa,bb,100)
[x,y] = hyperplane([w[0],w[1]],-1*theta,xx)
plt.plot(x,y,'-',color='red')
plt.show()
