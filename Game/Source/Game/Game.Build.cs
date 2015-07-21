// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class Game : ModuleRules
{
    private string modulePath { get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); } }
    private string[] libraryNames = new string[]
    {
        "WiiYourself",
        "Photon",
        "LoadBalancing",
        "Common",
        "Chat"
    };

	public Game(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "MyoPlugin" });

        foreach (var libName in libraryNames)
            LoadLibrary(Target, libName);
	}

    private bool LoadLibrary(TargetInfo target, string libName)
    {
        bool isLibrarySupported = false;
        string libPath = Path.GetFullPath(Path.Combine(modulePath, libName));
        if ((target.Platform == UnrealTargetPlatform.Win64) || (target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;
            string librariesPath = Path.Combine(libPath, "lib");
            string[] libFilePaths = Directory.GetFiles(librariesPath, "*.lib");
            if (libFilePaths.GetLength(0) > 0)
            {
                // Add *.lib File
                foreach (string libFilePath in libFilePaths)
                    PublicAdditionalLibraries.Add(libFilePath);
            }
        }
        if (isLibrarySupported)
        {
            // Include Path
            PublicIncludePaths.Add(Path.Combine(libPath, "inc"));
        }
        //Definitions.Add(string.Format("WITH_LIB_BINDING = { 0 }", isLibrarySupported ? 1 : 0));
        return isLibrarySupported;
    }
}
