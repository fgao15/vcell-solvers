      SUBROUTINEPCLUPF(MODIFY,N,IJA,A,LEV,NZMAX,MAXBLK,IBLKN,
     *IBLKS,NZL,NZU,IJL,IJU,IRSW,LD,U,IUT,LEVL,IPT,IPVT,
     *HEAD,SUM,ROW)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      LOGICALMODIFY
      INTEGERN,IJA(*),LEV,NZMAX,MAXBLK,IBLKN,IBLKS(*),NZL,
     *NZU,IJL(*),IJU(*),IRSW(*),IUT(*),IPT(*),LEVL(*),
     *IPVT(*),HEAD(*)
      DOUBLEPRECISIONA(*),LD(*),U(*),SUM(*),ROW(*)
      INTEGERIERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,LUDONE,IBLK,
     *MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,IFRMAT
      COMMON/PCCOM1/IERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,
     *LUDONE,IBLK,MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,
     *IFRMAT
      SAVE/PCCOM1/
      DOUBLEPRECISIONACCEL,RESID,ACC2
      COMMON/PCCOM2/ACCEL,RESID,ACC2
      SAVE/PCCOM2/
      INTEGERI,II,I1,I2
      INTEGERNP1,LEVP2,IBLKSI,IROW,IRB,BASE,LEV0,LEVMAX
      INTEGERONE
      DOUBLEPRECISIONTACC2
      ONE=1
      IF(MODIFY)THEN
      TACC2=ACC2
      ELSE
      TACC2=0.0D0
      ENDIF
      IJL(1)=N+2
      IJU(1)=N+2
      NP1=N+1
      NZL=NP1
      NZU=NP1
      LEVMAX=LEV+4
      LEV0=(IBLKN-1)*LEVMAX
      CALLPC0V(N*MAXBLK,ROW)
      CALLDCOPY(N,A,ONE,LD,ONE)
      IF(ACCEL.NE.0.0D0)THEN
      DO1I=1,N
      LD(I)=LD(I)+ACCEL
1     CONTINUE
      ENDIF
      DO3I=1,N*MAXBLK
      LEVL(I)=LEV0+LEVMAX
3     CONTINUE
      I2=0
      IROW=0
      DO5II=1,IBLKN
      LEVP2=LEV0+LEV+2
      IBLKSI=IBLKS(II)
      IRB=I2
      I1=IRB+1
      I2=IRB+IBLKSI
      BASE=1
      DO7I=1,IBLKSI
      IROW=IROW+1
      IRSW(IROW)=IROW
      CALLPCLUP1(NP1,LEV0,IROW,IJA,A,LD,HEAD(I),LEVL(BASE),
     *IPT(BASE),ROW(BASE),I1,I2)
      CALLPCLUP2(HEAD(I),LEVP2,NP1,IJU,IUT,U,
     *LEVL(BASE),IPT(BASE),ROW(BASE),SUM(I),I1,I2)
      BASE=BASE+N
7     CONTINUE
      CALLPCLUP4(IRB,IBLKSI,LEVP2,N,NP1,NZMAX,HEAD,NZL,
     *NZU,IJL,IJU,IUT,IRSW,LD,U,LEVL,IPT,IPVT,ROW,SUM,
     *LEV0,TACC2)
      IF(IERR.NE.0)THEN
      RETURN
      ENDIF
      DO9I=1,IBLKSI-1
      IRSW(IRB+I)=IRSW(IRB+IPVT(I))
9     CONTINUE
      IRSW(I2)=I2
      LEV0=LEV0-LEVMAX
5     CONTINUE
      RETURN
      END