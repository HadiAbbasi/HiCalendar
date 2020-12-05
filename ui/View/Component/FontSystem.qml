import QtQuick 2.14

Item {

    property var getContentFont: contentFont
    property var getContentFontLightFarsi: contentFontLightFarsi
    property var getContentFontLight: contentFontLight
    property var getContentFontFarsi: contentFontFarsi
    property var getAwesomeRegular: fontAwesomeRegular
    property var getAwesomeSolid: fontAwesomeSolid
    property var getAwesomeBrand: fontAwesomeBrand

    FontLoader {
        id: fontAwesomeBrand
        source: ASSETS+"fonts/Font Awesome 5 Brands-Regular-400.otf"
    }

    FontLoader {
        id: fontAwesomeRegular
        source: ASSETS+"fonts/Font Awesome 5 Free-Regular-400.otf"
    }

    FontLoader {
        id: fontAwesomeSolid
        source: ASSETS+"fonts/Font Awesome 5 Free-Solid-900.otf"
    }

    FontLoader {
        id: contentFont
        source: ASSETS+"fonts/Shabnam-Medium.ttf"
    }

    FontLoader {
        id: contentFontLight
        source: ASSETS+"fonts/Shabnam-Light.ttf"
    }

    FontLoader {
        id: contentFontLightFarsi
        source: ASSETS+"fonts/Shabnam-Light-FD.ttf"
    }

    FontLoader {
        id: contentFontFarsi
        source: ASSETS+"fonts/Shabnam-Medium-FD.ttf"
    }
}
