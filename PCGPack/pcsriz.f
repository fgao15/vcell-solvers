      SUBROUTINEPCSRIZ(N,IJA,IJAP)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERN,IJA(*),IJAP(*)
      INTEGERJ
      CALLPC0VI(N,IJAP)
      DO1J=N+2,IJA(N+1)-1
      IJAP(IJA(J))=IJAP(IJA(J))+1
1     CONTINUE
      IJAP(1)=IJAP(1)+N+2
      DO3J=1,N-1
      IJAP(J+1)=IJAP(J+1)+IJAP(J)
3     CONTINUE
      IJAP(N+1)=IJAP(N)
      RETURN
      END
