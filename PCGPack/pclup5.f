      SUBROUTINEPCLUP5(NP1,IROW,HEAD,NZMAX,PV,IPT,LEVL,ROW,
     *NZL,NZU,IJL,IJU,IUT,LD,U,LEVB)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERNP1,IROW,HEAD,NZMAX,NZL,NZU,IPT(*),LEVL(*),
     *IJL(*),IJU(*),IUT(*),LEVB
      DOUBLEPRECISIONPV,LD(*),U(*),ROW(*)
      INTEGERIERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,LUDONE,IBLK,
     *MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,IFRMAT
      COMMON/PCCOM1/IERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,
     *LUDONE,IBLK,MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,
     *IFRMAT
      SAVE/PCCOM1/
      INTEGERIPRE1,IPRE2,RATIO
      COMMON/PCCOM3/IPRE1,IPRE2,RATIO
      SAVE/PCCOM3/
      INTEGERJ,K
      LD(IROW)=PV
      J=HEAD
      IF(HEAD.EQ.0)THEN
      IJL(IROW+1)=NZL+1
      IJU(IROW+1)=NZU+1
      ELSE
      DO1K=1,IROW
      IF(J.GE.IROW)THEN
      GOTO2
      ENDIF
      IF(ROW(J).NE.0.0D0)THEN
      NZL=NZL+1
      IF(NZL.GT.NZMAX)THEN
      NZL=NZL*NP1/IROW
      NZU=NZU*NP1/IROW
      IERR=3
      RETURN
      ENDIF
      IJL(NZL)=J
      LD(NZL)=ROW(J)*LD(J)
      ENDIF
      J=IPT(J)
1     CONTINUE
2     CONTINUE
      IJL(IROW+1)=NZL+1
      IF(J.EQ.IROW)THEN
      J=IPT(J)
      ENDIF
      DO3K=IROW+1,NP1
      IF(J.GE.NP1)THEN
      GOTO4
      ENDIF
      IF(ROW(J).NE.0.0D0)THEN
      NZU=NZU+1
      IF(NZU.GT.NZMAX)THEN
      NZL=NZL*NP1/IROW
      NZU=NZU*NP1/IROW
      IERR=3
      RETURN
      ENDIF
      IJU(NZU)=J
      U(NZU)=ROW(J)
      IUT(NZU)=LEVL(J)-LEVB
      ENDIF
      J=IPT(J)
3     CONTINUE
4     CONTINUE
      IJU(IROW+1)=NZU+1
      ENDIF
      RETURN
      END
