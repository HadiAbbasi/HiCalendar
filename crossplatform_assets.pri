SOURCES += src/assetsmanager.cpp

HEADERS += include/assetsmanager.hpp

source = $$PWD/assets
target = $$OUT_PWD/assets
target ~= s,\\\\\\.?\\\\,\\,

win32{
    message("target is Windows x86")
    if(exists($$OUT_PWD/assets)){
        message("assets exists!")
    } else {
        message("assets not exists!")
	source = $$replace(source, /, \\)
	target = $$replace(target, /, \\)
	target ~= s,\\\\\\.?\\\\,\\,
	copyCommand += xcopy /E /I /Y \"$$source\" \"$$target\"
	copydeploymentfolders.commands += $$copyCommand
	first.depends += $(first) copydeploymentfolders
	export(first.depends)
	export(copydeploymentfolders.commands)
	QMAKE_EXTRA_TARGETS += first copydeploymentfolders
    }
}

win64{
    message("target is Windows x64")
    if(exists($$OUT_PWD/assets)){
        message("assets exists!")
    }
    else
    {
        message("assets not exists!")
	source = $$replace(source, /, \\)
	target = $$replace(target, /, \\)
	target ~= s,\\\\\\.?\\\\,\\,
	copyCommand += xcopy /E /I /Y \"$$source\" \"$$target\"
	copydeploymentfolders.commands += $$copyCommand
	first.depends += $(first) copydeploymentfolders
	export(first.depends)
	export(copydeploymentfolders.commands)
	QMAKE_EXTRA_TARGETS += first copydeploymentfolders
    }
}

unix:!android{
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

android{
    message("target is android")
    QT += androidextras
    COMMON_DATA.path = /assets
    COMMON_DATA.files = $$files($$PWD/assets/*)
    INSTALLS += COMMON_DATA
}

macos{
    message("target is macOS")
    CONFIG+=sdk_no_version_check
    QT += macextras
}

mac{
    message("target is macOS")
    CONFIG+=sdk_no_version_check
    QT += macextras
}

ios{
    message("target is iOS")
    CONFIG += sdk_no_version_check
}

export(INSTALLS)
