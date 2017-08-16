      SUBROUTINEPCUNPK(N,IPARM,RPARM)
      IMPLICITDOUBLEPRECISION(A-H,O-Z)
      INTEGERN,IPARM(*)
      DOUBLEPRECISIONRPARM(*)
      INTEGERIERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,LUDONE,IBLK,
     *MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,IFRMAT
      COMMON/PCCOM1/IERR,ITMAX,ITEST,KMAX,IFL,IPRE,PBLK,
     *LUDONE,IBLK,MNEED,ITS,RSDONE,NOVERF,RED1,RED2,IERR2,
     *IFRMAT
      SAVE/PCCOM1/
      DOUBLEPRECISIONACCEL,RESID,ACC2
      COMMON/PCCOM2/ACCEL,RESID,ACC2
      SAVE/PCCOM2/
      INTEGERIPRE1,IPRE2,RATIO
      COMMON/PCCOM3/IPRE1,IPRE2,RATIO
      SAVE/PCCOM3/
      INTEGERISTOP,IRESD,INORM,ISAME,ISTATP,IRSDS,IOUT,JOUT,ISTATS,
     *ISTAT1,ISTAT2
      DOUBLEPRECISIONEPS1,EPS2
      COMMON/PCSTIC/ISTOP,IRESD,INORM,ISAME,ISTATP,IRSDS,IOUT,JOUT,
     *ISTATS,ISTAT1,ISTAT2
      COMMON/PCSTRC/EPS1,EPS2
      SAVE/PCSTIC/,/PCSTRC/
      INTEGERISRT,IJASGN,ISX0,IFORM
      COMMON/PCVERI/ISRT,IJASGN,ISX0,IFORM
      SAVE/PCVERI/
      INTEGERIERRV,IERR2V,IERRP,IERR2P
      DOUBLEPRECISIONFZERO,FONE
      IPARM(75)=101
      IERR=0
      IERR2=0
      IERRV=0
      IERR2V=0
      IERRP=0
      IERR2P=0
      RATIO=2
      FZERO=0.D0
      FONE=1.D0
      IF(IPARM(1).LT.200)THEN
      ITMAX=IPARM(2)
      IF(ITMAX.LT.1)THEN
      IERR=102
      GOTO1000
      ENDIF
      ITEST=IPARM(3)
      IF(ITEST.LT.1.OR.ITEST.GT.N)THEN
      IERR=103
      GOTO1000
      ENDIF
      IOUT=IPARM(5)
      JOUT=IPARM(6)
      ISTATP=IPARM(4)
      ISTAT1=MOD(ISTATP,10)
      ISTAT2=ISTATP/10
      IF(ISTAT1.LT.0.OR.ISTAT2.LT.0.OR.ISTAT1.GT.2.OR.
     *ISTAT2.GT.2)THEN
      IERR=104
      GOTO1000
      ENDIF
      KMAX=IPARM(7)
      IF(KMAX.LT.0)THEN
      IERR=107
      GOTO1000
      ENDIF
      IFL=IPARM(8)
      IF(IFL.LT.-1)THEN
      IERR=108
      GOTO1000
      ENDIF
      IPRE=IPARM(9)
      IF(IPRE.LT.1.OR.IPRE.GT.3)THEN
      IERR=109
      GOTO1000
      ENDIF
      IPRE=IPRE-1
      LUDONE=IPARM(10)
      RSDONE=0
      IBLK=IPARM(11)
      IF(IBLK.LT.0)THEN
      IERR=111
      GOTO1000
      ENDIF
      NOVERF=1
      IRESD=1-IRESD
      ACCEL=RPARM(1)
      ELSE
      CALLPCVUNP(N,IPARM,RPARM,IERRV,IERR2V)
      CALLPCPUNP(N,IPARM,RPARM,IERRP,IERR2P)
      NOVERF=IPARM(2)
      IF(NOVERF.LT.0.OR.NOVERF.GT.1)THEN
      IERR2=2
      IERR=16
      GOTO1000
      ENDIF
      IBLK=IPARM(3)
      IF(IBLK.LT.0)THEN
      IERR2=3
      IERR=16
      GOTO1000
      ENDIF
      KMAX=IPARM(4)
      IF(KMAX.LT.0)THEN
      IERR2=4
      IERR=16
      GOTO1000
      ENDIF
      ITMAX=IPARM(5)
      IF(ITMAX.LT.1)THEN
      IERR2=5
      IERR=16
      GOTO1000
      ENDIF
      RSDONE=IPARM(11)
      IF(RSDONE.LT.-1.OR.RSDONE.GT.2)THEN
      IERR2=11
      IERR=16
      GOTO1000
      ENDIF
      RED1=IPARM(12)
      IF(RED1.LT.0.OR.RED1.GT.N)THEN
      IERR2=12
      IERR=16
      GOTO1000
      ENDIF
      RED2=IPARM(13)
      IF((RED2.NE.0.AND.RED1.EQ.0).OR.
     1RED2.LT.RED1.OR.RED2.GT.N)THEN
      IERR2=13
      IERR=16
      GOTO1000
      ENDIF
      LUDONE=IPARM(14)
      IF(LUDONE.LT.0.OR.LUDONE.GT.2)THEN
      IERR2=14
      IERR=16
      GOTO1000
      ENDIF
      IF(RSDONE.EQ.2.AND.LUDONE.EQ.1)THEN
      LUDONE=2
      ENDIF
      IFL=IPARM(15)
      IF(IFL.LT.-1)THEN
      IERR2=15
      IERR=16
      GOTO1000
      ENDIF
      IPRE=IPARM(16)
      IF(IPRE.LT.0.OR.IPRE.GT.2)THEN
      IERR2=16
      IERR=16
      GOTO1000
      ENDIF
      PBLK=IPARM(17)
      IF(PBLK.LT.-1.OR.PBLK.GT.1)THEN
      IERR2=17
      IERR=16
      GOTO1000
      ENDIF
      IF(NOVERF.EQ.1)THEN
      IFORM=IPARM(21)
      ISRT=IPARM(22)
      IF(IFORM.LT.-1.OR.IFORM.GT.1)THEN
      IERR2=21
      IERR=16
      GOTO1000
      ENDIF
      IF(ISRT.NE.0.AND.ISRT.NE.1)THEN
      IERR2=22
      IERR=16
      GOTO1000
      ENDIF
      ENDIF
      ITEST=IPARM(31)
      IF(ITEST.LT.0.OR.ITEST.GT.N)THEN
      IERR2=31
      IERR=16
      GOTO1000
      ENDIF
      IF(ITEST.EQ.0)THEN
      ITEST=1
      ENDIF
      IRESD=IPARM(32)
      IF(IRESD.LT.0.OR.IRESD.GT.1)THEN
      IERR2=32
      IERR=16
      GOTO1000
      ENDIF
      INORM=IPARM(33)
      IF(INORM.LT.-1.OR.INORM.GT.1)THEN
      IERR2=33
      IERR=16
      GOTO1000
      ENDIF
      ISTOP=IPARM(34)
      IF(ISTOP.LT.0.OR.ISTOP.GT.1)THEN
      IERR2=34
      IERR=16
      GOTO1000
      ENDIF
      ISAME=IPARM(35)
      IF(ISAME.LT.0)THEN
      IERR2=35
      IERR=16
      GOTO1000
      ENDIF
      IF(ISAME.EQ.0)THEN
      ISAME=5
      ENDIF
      ISTATS=IPARM(36)
      IF(ISTATS.LT.0.OR.ISTATS.GT.2)THEN
      IERR2=36
      IERR=16
      GOTO1000
      ENDIF
      ISTAT1=IPARM(37)
      IF(ISTAT1.LT.0.OR.ISTAT1.GT.2)THEN
      IERR2=37
      IERR=16
      GOTO1000
      ENDIF
      IOUT=IPARM(38)
      ISTAT2=IPARM(39)
      IF(ISTAT2.LT.0.OR.ISTAT2.GT.2)THEN
      IERR2=38
      IERR=16
      GOTO1000
      ENDIF
      JOUT=IPARM(40)
      ISTATP=10*ISTAT2+ISTAT1
      ACCEL=RPARM(1)
      ACC2=RPARM(2)
      IF(ACC2.LT.FZERO.OR.ACC2.GT.FONE)THEN
      IERR2=2
      IERR=18
      GOTO1000
      ENDIF
      EPS1=RPARM(3)
      IF(EPS1.LE.FZERO)THEN
      IERR2=3
      IERR=18
      GOTO1000
      ENDIF
      EPS2=RPARM(4)
      IF(EPS2.LE.FZERO)THEN
      IERR2=4
      IERR=18
      GOTO1000
      ENDIF
      ENDIF
 1000 CONTINUE
      IF(IERR.EQ.0.AND.IERRV.EQ.0.AND.IERRP.EQ.0)THEN
      MNEED=0
      ITS=0
      IERR=0
      IERR2=0
      ELSE
      IF(IERRV.NE.0)THEN
      IF(IERR.EQ.0.OR.IERRV.LT.IERR.OR.
     1(IERRV.EQ.IERR.AND.IERR2V.LT.IERR2))THEN
      IERR=IERRV
      IERR2=IERR2V
      ENDIF
      ENDIF
      IF(IERRP.NE.0)THEN
      IF(IERR.EQ.0.OR.IERRP.LT.IERR.OR.
     1(IERRP.EQ.IERR.AND.IERR2P.LT.IERR2))THEN
      IERR=IERRP
      IERR2=IERR2P
      ENDIF
      ENDIF
      ENDIF
      RETURN
      END