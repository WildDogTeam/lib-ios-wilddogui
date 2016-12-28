#
#  Be sure to run `pod spec lint WilddogUI.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "WilddogUI"
  s.version      = "0.0.1"
  s.summary      = "WilddogUI 的源码集成版本。"

  s.description  = <<-DESC
WilddogUI 的源码集成版本。供内部开发使用。
                   DESC

  s.homepage     = "https://www.wilddog.com/"
  s.license      = "MIT"
  s.author       = "Wilddog Team"
  s.platform     = :ios, "9.0"

  s.source       = { :git => "", :tag => "0.0.1" }
  s.public_header_files = "WilddogUI/WilddogUI.h", "WilddogUI/**/*.h"
  s.source_files  = "WilddogUI/**/*.{h,m}"

  s.module_map = 'WilddogUI/WilddogUI.modulemap'
  s.xcconfig     = { "OTHER_LDFLAGS" => "-ObjC", "FRAMEWORK_SEARCH_PATHS" => "${PODS_ROOT}/WilddogSync ${PODS_ROOT}/WilddogCore"}

  s.dependency "Wilddog/Sync"
end
