      SUBROUTINEPCVUNP(N,IPARM,RPARM,IERRV,IERR2V)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERN,IPARM(*),IERRV,IERR2V
      DOUBLEPRECISIONRPARM(*)
      INTEGERIERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,LUDONE,IBLK,
     *MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,IFRMAT
      COMMON/PCCOM1/IERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,
     *LUDONE,IBLK,MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,
     *IFRMAT
      SAVE/PCCOM1/
      IERRV=0
      IERR2V=0
      IFRMAT=0
      
 1000 CONTINUE
      RETURN
      END