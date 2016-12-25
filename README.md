Unreal Engine 4 Git Source Control Plugin
-----------------------------------------

[![Join the chat at https://gitter.im/SRombauts/UE4GitPlugin](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/SRombauts/UE4GitPlugin?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

UE4GitPlugin is a simple Git Source Control Plugin for Unreal Engine

**It has been integrated by default in UE4.7 in "Beta".**

This is a developement fork to be able to develop a "v2" of the plugin alongside the existing git plugin inside currents version of the engine.

Have a look at the [Git Plugin Tutorial on the Wiki](https://wiki.unrealengine.com/Git_source_control_%28Tutorial%29).

### Status

This Git Source Control Plugin is now part of the default Unreal Engine 4.7

Beta version 1.0:
- initialize a new Git local repository ('git init') to manage your UE4 Game Project.
- create an appropriate .gitignore file as part as initialization
- can also make the initial commit
- display status icons to show modified/added/deleted/untracked files
- show history of a file
- visual diff of a blueprint against depot or between previous versions of a file
- revert modifications of a file
- add, delete, rename a file
- checkin/commit a file (cannot handle atomically more than 20 files)
- migrate an asset between two projects if both are using Git
- solve a merge conflict on a blueprint
- show current branch name in status text
- Sync to Pull the current branch if there is no local modified files
- git LFS (Github & Gitlab), git-annexe and/or git-media are working under Windows
- Windows, Mac and Linux

#### What *cannot* be done presently (TODO list for v1.0, ordered by priority):
- tags: implement ISourceControlLabel to manage git tags
- Branch is not in the current Editor workflow (but on Epic Roadmap)
- Pull/Fetch/Push are not in the current Editor workflow
- Amend a commit is not in the current Editor workflow
- configure user name & email ('git config user.name' & git config user.email')

#### Known issues:
- the Editor does not show deleted files (only when deleted externaly?)
- the Editor does not show missing files
- the Editor does not show .uproject file
- missing localisation for git specific messages
- displaying states of 'Engine' assets (also needs management of 'out of tree' files)
- issue #22: A Move/Rename leaves a redirector file behind
- improve the 'Init' window text, hide it if connection is already done, auto connect
- reverting an asset does not seem to update content in Editor! Issue in Editor?
- renaming a Blueprint in Editor leaves a tracker file, AND modify too much the asset to enable git to track its history through renaming
- file history show Changelist as signed integer instead of hexadecimal SHA1
- standard Editor commit dialog ask if user wants to "Keep Files Checked Out" => no use for Git or Mercurial CanCheckOut()==false

#### In-code TODO list (internal roadmap):

- FGitConnectWorker::Execute (While project not in Git source control)
  Improve error message "You should check out a working copy..."
  => double error message (and in reverse order) with "Project is not part of a Git working copy"

- FGitSourceControlRevision::GetBranchSource() const
  if this revision was copied from some other revision, then that source revision should
	be returned here (this should be determined when history is being fetched)
- FGitSourceControlState::GetBaseRevForMerge()
  get revision of the merge-base (https://www.kernel.org/pub/software/scm/git/docs/git-merge-base.html)
	
- FGitConnectWorker::Execute()
  popup to propose to initialize the git repository "git init + .gitignore"

- FGitSyncWorker (GitSourceControlOperations.h)
  git fetch remote(s) to be able to show files not up-to-date with the serveur
- FGitSourceControlState::IsCurrent() const
  check the state of the HEAD versus the state of tracked branch on remote

- FGitSourceControlRevision::GetFileSize() const
	git log does not give us the file size, but we could run a specific command

- GitSourceControlUtils::CheckGitAvailability
  also check Git config user.name & user.email

Windows:
- GitSourceControlUtils::FindGitBinaryPath
  use the Windows registry to find Git

Mac:
- GitSourceControlUtils::RunCommandInternalRaw
  Specifying the working copy (the root) of the git repository (before the command itself)
	does not work in UE4.1 on Mac/Linux if there is a space in the path ("/Users/xxx/Unreal Project/MyProject")

Bug reports?
- FGitSourceControlRevision::Get
  Bug report: a counter is needed to avoid overlapping files; temp files are not (never?) released by Editor!

- GitSourceControlUtils::UpdateCachedStates
  // State->TimeStamp = InState.TimeStamp; // Bug report: Workaround a bug with the Source Control Module not updating file state after a "Save"

### Getting started

Quick demo of the Git Plugin on Unreal Engine 4.12 (preview) 
[![Git Plugin on Unreal Engine 4.12 (preview)](https://img.youtube.com/vi/rRhPl9vL58Q/0.jpg)](https://youtu.be/rRhPl9vL58Q)

#### Install Git

Under Windows 64bits, you could either:
- install a standalone Git, usually in "C:\Program Files (x86)\Git\bin\git.exe".
- or copy a [portable Git](https://code.google.com/p/msysgit/downloads/list?can=1&q=PortableGit)
inside "<UnrealEngine>/Engine/Binaries/ThirdParty/git/Win32".

#### Activate Git Source Control for your Game Project

Load your Game Project, then open:

```
File->Connect To Source Control... -> Git: Accept Settings
```

See also the [Source Control official Documentation](https://docs.unrealengine.com/latest/INT/Engine/UI/SourceControl/index.html)

### License

Copyright (c) 2014-2015 Sebastien Rombauts (sebastien.rombauts@gmail.com)

Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
or copy at http://opensource.org/licenses/MIT)

## How to contribute
### GitHub website
The most efficient way to help and contribute to this wrapper project is to
use the tools provided by GitHub:
- please fill bug reports and feature requests here: https://github.com/SRombauts/UE4GitPlugin/issues
- fork the repository, make some small changes and submit them with independent pull-requests

### Contact
You can also email me directly, I will answer any questions and requests.

### Coding Style Guidelines
The source code follow the UnreaEngine official [Coding Standard](https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html) :
- CamelCase naming convention, with a prefix letter to differentiate classes ('F'), interfaces ('I'), templates ('T')
- files (.cpp/.h) are named like the class they contains
- Doxygen comments, documentation is located with declaration, on headers
- Use portable common features of C++11 like nullptr, auto, range based for, override keyword
- Braces on their own line
- Tabs to indent code, with a width of 4 characters

## See also

- [Git Source Control Tutorial on the Wikis](https://wiki.unrealengine.com/Git_source_control_(Tutorial))
- [UE4 Git Plugin website](http://srombauts.github.com/UE4GitPlugin)

- [ue4-hg-plugin for Mercurial (and bigfiles)](https://github.com/enlight/ue4-hg-plugin)
