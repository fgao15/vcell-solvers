      SUBROUTINEPCSRIX(N,IJA,IJAP)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERN,IJA(*),IJAP(*)
      INTEGERI,J
      DO1I=N,1,-1
CDIR$ IVDEP
CVDIR IGNORE RECRDEPS
      DO3J=IJA(I),IJA(I+1)-1
      IJAP(IJA(J))=IJAP(IJA(J))-1
      IJAP(IJAP(IJA(J)))=I
3     CONTINUE
1     CONTINUE
      RETURN
      END
