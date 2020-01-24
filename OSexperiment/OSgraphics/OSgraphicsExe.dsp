# Microsoft Developer Studio Project File - Name="OSgraphicsExe" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=OSgraphicsExe - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OSgraphicsExe.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OSgraphicsExe.mak" CFG="OSgraphicsExe - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OSgraphicsExe - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "OSgraphicsExe - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OSgraphicsExe - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "OSgraphicsExe - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "OSgraphicsExe - Win32 Release"
# Name "OSgraphicsExe - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Arc.cpp
# End Source File
# Begin Source File

SOURCE=.\AreaFtr.cpp
# End Source File
# Begin Source File

SOURCE=.\Circle.cpp
# End Source File
# Begin Source File

SOURCE=.\Cirque.cpp
# End Source File
# Begin Source File

SOURCE=.\Feature.cpp
# End Source File
# Begin Source File

SOURCE=.\LineFtr.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExe.cpp
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExe.rc
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExeDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExeView.cpp
# End Source File
# Begin Source File

SOURCE=.\PointFtr.cpp
# End Source File
# Begin Source File

SOURCE=.\Poly.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyLine.cpp
# End Source File
# Begin Source File

SOURCE=.\Rectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Square.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Text.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllGraphicHead.h
# End Source File
# Begin Source File

SOURCE=.\Arc.h
# End Source File
# Begin Source File

SOURCE=.\AreaFtr.h
# End Source File
# Begin Source File

SOURCE=.\Circle.h
# End Source File
# Begin Source File

SOURCE=.\Cirque.h
# End Source File
# Begin Source File

SOURCE=.\Feature.h
# End Source File
# Begin Source File

SOURCE=.\LineFtr.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MyTimer.h
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExe.h
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExeDoc.h
# End Source File
# Begin Source File

SOURCE=.\OSgraphicsExeView.h
# End Source File
# Begin Source File

SOURCE=.\PointFtr.h
# End Source File
# Begin Source File

SOURCE=.\Poly.h
# End Source File
# Begin Source File

SOURCE=.\PolyLine.h
# End Source File
# Begin Source File

SOURCE=.\Rectangle.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Square.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Text.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\OSgraphicsExe.ico
# End Source File
# Begin Source File

SOURCE=.\res\OSgraphicsExe.rc2
# End Source File
# Begin Source File

SOURCE=.\res\OSgraphicsExeDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
