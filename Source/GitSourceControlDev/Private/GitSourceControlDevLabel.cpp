// Copyright (c) 2014-2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
//
// Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
// or copy at http://opensource.org/licenses/MIT)

#include "GitSourceControlDevPrivatePCH.h"
#include "GitSourceControlDevLabel.h"
#include "GitSourceControlDevModule.h"
#include "GitSourceControlDevProvider.h"
#include "GitSourceControlDevRevision.h"
#include "GitSourceControlDevUtils.h"

const FString& FGitSourceControlDevLabel::GetName() const
{
	return Name;
}

bool FGitSourceControlDevLabel::GetFileRevisions( const TArray<FString>& InFiles, TArray< TSharedRef<ISourceControlRevision, ESPMode::ThreadSafe> >& OutRevisions ) const
{
	bool bCommandOK = true;

	return bCommandOK;
}

bool FGitSourceControlDevLabel::Sync( const TArray<FString>& InFilenames ) const
{
//	GitSourceControlDevUtils::CheckFilenames(InFilenames);

	FGitSourceControlDevModule& GitSourceControlDev = FModuleManager::LoadModuleChecked<FGitSourceControlDevModule>( "GitSourceControlDev" );
	FGitSourceControlDevProvider& Provider = GitSourceControlDev.GetProvider();

	TArray<FString> Results;
	TArray<FString> Parameters;
	TArray<FString> ErrorMessages;
	Parameters.Add(FString::Printf(TEXT("--revision %i"), Revision));

	// TODO SRombauts run command checkout to label
	bool bCommandOK = false;
//	bool bCommandOK = GitSourceControlDevUtils::RunCommand(TEXT("checkout"), Parameters, InFilenames, Results, ErrorMessages));

	// TODO SRombauts also update cached state
	{
//		bCommandOK &= GitSourceControlDevUtils::RunCommand(TEXT("status"), InFilenames, StatusParameters, ResultsXml, ErrorMessages, Provider.GetUserName());
//		GitSourceControlDevUtils::ParseStatusResults(ResultsXml, ErrorMessages, Provider.GetUserName(), Provider.GetWorkingCopyRoot(), OutStates);
//		GitSourceControlDevUtils::UpdateCachedStates(OutStates);
	}

	return bCommandOK;
}