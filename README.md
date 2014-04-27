NovAlympique
============

Un Programme Blagueur (un faux virus un peu flippant)

Exemple de fichier CodeBlocks pour le compiler le projet

<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<CodeBlocks_project_file>
	<FileVersion major="1" minor="6" />
	<Project>
		<Option title="NovAlympe" />
		<Option pch_mode="2" />
		<Option compiler="gcc" />
		<Build>
			<Target title="Debug">
				<Option output="bin\Debug\NovAlympe" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj\Debug\" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-g" />
					<Add option="-DSFML_STATIC" />
					<Add directory="D:\SFML\include" />
				</Compiler>
				<Linker>
					<Add library="sfml-graphics-s-d" />
					<Add library="sfml-audio-s-d" />
					<Add library="sfml-window-s-d" />
					<Add library="sfml-network-s-d" />
					<Add library="sfml-system-s-d" />
					<Add directory="D:\SFML\lib" />
				</Linker>
			</Target>
			<Target title="Release">
				<Option output="bin\Release\NovAlympe" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj\Release\" />
				<Option type="0" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-O2" />
					<Add option="-DSFML_STATIC" />
					<Add directory="D:\SFML\include" />
				</Compiler>
				<Linker>
					<Add option="-s" />
					<Add library="sfml-graphics-s" />
					<Add library="sfml-audio-s" />
					<Add library="sfml-window-s" />
					<Add library="sfml-network-s" />
					<Add library="sfml-system-s" />
					<Add directory="D:\SFML\lib" />
				</Linker>
			</Target>
		</Build>
		<Compiler>
			<Add option="-Wall" />
			<Add option="-DSFML_STATIC" />
		</Compiler>
		<Unit filename="include\Screen.h" />
		<Unit filename="include\capture.h" />
		<Unit filename="include\lodepng.h" />
		<Unit filename="main.cpp" />
		<Unit filename="ressources.rc">
			<Option compilerVar="WINDRES" />
		</Unit>
		<Unit filename="src\Screen.cpp" />
		<Unit filename="src\capture.cpp" />
		<Unit filename="src\lodepng.cpp" />
		<Extensions>
			<code_completion />
			<debugger />
			<envvars />
		</Extensions>
	</Project>
</CodeBlocks_project_file>
