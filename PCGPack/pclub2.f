      SUBROUTINEPCLUB2(MODIFY,N,K,I1,I2,IBLKSK,NLI,JCOL,IROW,
     *IJU,U,ROW,ACC2)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      LOGICALMODIFY
      INTEGERN,K,I1,I2,IBLKSK,NLI,JCOL(*),IROW(*),IJU(*)
      DOUBLEPRECISIONU(*),ROW(*),ACC2
      INTEGERJ,JCOLJ,LMIN,LNUM,RBASE,I
      DOUBLEPRECISIONT
      IF(MODIFY)THEN
      DO1J=1,NLI
      JCOLJ=JCOL(J)
      LMIN=IJU(JCOLJ)
      LNUM=IJU(JCOLJ+1)
      LNUM=LNUM-LMIN
      RBASE=0
      DO3I=I1,I2
      T=-ROW(RBASE+JCOLJ)
      IF(T.NE.0.0D0)THEN
      CALLPCLUB5(IROW,I,K,LNUM,IJU(LMIN),T,U(LMIN),ROW(
     *RBASE+1),ACC2)
      ENDIF
      RBASE=RBASE+N
3     CONTINUE
1     CONTINUE
      ELSE
      DO5J=1,NLI
      JCOLJ=JCOL(J)
      LMIN=IJU(JCOLJ)
      LNUM=IJU(JCOLJ+1)
      LNUM=LNUM-LMIN
      RBASE=0
      DO7I=I1,I2
      T=-ROW(RBASE+JCOLJ)
      IF(T.NE.0.0D0)THEN
      CALLPCAXPY(LNUM,IJU(LMIN),T,U(LMIN),ROW(RBASE+1))
      ENDIF
      RBASE=RBASE+N
7     CONTINUE
5     CONTINUE
      ENDIF
      RETURN
      END
