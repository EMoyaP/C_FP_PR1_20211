##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Menu
ProjectName            :=UOCCoworking
ConfigurationName      :=Menu
WorkspacePath          :=/home/uoc/Desktop/UOCCoworking_PR1_enu
ProjectPath            :=/home/uoc/Desktop/UOCCoworking_PR1_enu
IntermediateDirectory  :=./Menu
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=29/11/21
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCCoworking.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)./include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -Wno-unused-result -g -O2 -Wall $(Preprocessors)
CFLAGS   :=  -Wno-unused-result -g -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IntermediateDirectory)/src_coworkingcenter.c$(ObjectSuffix) $(IntermediateDirectory)/src_menu.c$(ObjectSuffix) $(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IntermediateDirectory)/src_coworker.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Menu || $(MakeDirCommand) ./Menu


$(IntermediateDirectory)/.d:
	@test -d ./Menu || $(MakeDirCommand) ./Menu

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_api.c$(ObjectSuffix): src/api.c $(IntermediateDirectory)/src_api.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_api.c$(DependSuffix): src/api.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_api.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_api.c$(DependSuffix) -MM src/api.c

$(IntermediateDirectory)/src_api.c$(PreprocessSuffix): src/api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_api.c$(PreprocessSuffix) src/api.c

$(IntermediateDirectory)/src_coworkingcenter.c$(ObjectSuffix): src/coworkingcenter.c $(IntermediateDirectory)/src_coworkingcenter.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/coworkingcenter.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_coworkingcenter.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_coworkingcenter.c$(DependSuffix): src/coworkingcenter.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_coworkingcenter.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_coworkingcenter.c$(DependSuffix) -MM src/coworkingcenter.c

$(IntermediateDirectory)/src_coworkingcenter.c$(PreprocessSuffix): src/coworkingcenter.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_coworkingcenter.c$(PreprocessSuffix) src/coworkingcenter.c

$(IntermediateDirectory)/src_menu.c$(ObjectSuffix): src/menu.c $(IntermediateDirectory)/src_menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_menu.c$(DependSuffix): src/menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_menu.c$(DependSuffix) -MM src/menu.c

$(IntermediateDirectory)/src_menu.c$(PreprocessSuffix): src/menu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_menu.c$(PreprocessSuffix) src/menu.c

$(IntermediateDirectory)/src_test.c$(ObjectSuffix): src/test.c $(IntermediateDirectory)/src_test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_test.c$(DependSuffix): src/test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_test.c$(DependSuffix) -MM src/test.c

$(IntermediateDirectory)/src_test.c$(PreprocessSuffix): src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_test.c$(PreprocessSuffix) src/test.c

$(IntermediateDirectory)/src_coworker.c$(ObjectSuffix): src/coworker.c $(IntermediateDirectory)/src_coworker.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCCoworking_PR1_enu/src/coworker.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_coworker.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_coworker.c$(DependSuffix): src/coworker.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_coworker.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_coworker.c$(DependSuffix) -MM src/coworker.c

$(IntermediateDirectory)/src_coworker.c$(PreprocessSuffix): src/coworker.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_coworker.c$(PreprocessSuffix) src/coworker.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Menu/


