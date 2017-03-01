#include "histogramequalizationermenudialog.h"

#include <cassert>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <QFile>

#include "fileio.h"
#include "imagecanvas.h"
#include "histogramequalizationermaindialog.h"
#pragma GCC diagnostic pop

int ribi::HistogramEqualizationerMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc != 3 || (argv[1] != "-f" && argv[1] != "--filename"))
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  const std::string filename { argv[2] };
  if (!fileio::FileIo().IsRegularFile(filename))
  {
    std::cout << "Please give the filename of an existing file" << std::endl;
    return 0;
  }
  const QImage source(filename.c_str());
  assert(!source.isNull());
  const QImage result {
    HistogramEqualizationerMainDialog::DoHistogramEqualization(source)
  };
  assert(!result.isNull());
  const std::string result_filename { fileio::FileIo().GetTempFileName(".png") };
  result.save(result_filename.c_str());
  assert(fileio::FileIo().IsRegularFile(result_filename));

  const boost::shared_ptr<ImageCanvas> canvas {
    new ImageCanvas(result_filename,78)
  };
  std::cout << (*canvas) << std::endl;

  assert(fileio::FileIo().IsRegularFile(result_filename));
  fileio::FileIo().DeleteFile(result_filename);
  return 0;
}

ribi::About ribi::HistogramEqualizationerMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "HistogramEqualization",
    "tool to perform a histogram equalization",
    "the 6th of February 2014",
    "2008-2015",
    "http://www.richelbilderbeek.nl/ToolHistogramEqualizationer.htm",
    GetVersion(),
    GetVersionHistory()
  );
  a.AddLibrary("Canvas version: " + Canvas::GetVersion());
  a.AddLibrary("ImageCanvas version: " + ImageCanvas::GetVersion());
  return a;
}

ribi::Help ribi::HistogramEqualizationerMenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    GetAbout().GetFileTitle(),
    GetAbout().GetFileDescription(),
    {
      Help::Option('f',"filename","filename")
    },
    {
      GetAbout().GetFileTitle() + " -f MyPicture.png",
      GetAbout().GetFileTitle() + " --filename MyPicture.jpg"
    }
  );
}

std::string ribi::HistogramEqualizationerMenuDialog::GetVersion() const noexcept
{
  return "2.1";
}

std::vector<std::string> ribi::HistogramEqualizationerMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2008-07-11: version 1.0: initial Windows-only version",
    "2013-11-28: version 2.0: port to Qt",
    "2014-02-06: version 2.1: added command-line version"
  };
}
