      SUBROUTINEPCRDPP(NRED,C,IJA,A,RHS,D2I,X)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERNRED,C(*),IJA(*)
      DOUBLEPRECISIONA(*),RHS(*),D2I(*),X(*)
      INTEGERI,II,K
      DOUBLEPRECISIONSUM
      DO1I=1,NRED
      II=C(I)
      SUM=RHS(II)
      DO3K=IJA(II),IJA(II+1)-1
      SUM=SUM-A(K)*X(IJA(K))
3     CONTINUE
      X(II)=SUM*D2I(I)
1     CONTINUE
      RETURN
      END
