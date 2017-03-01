#ifndef HISTOGRAMEQUALIZATIONERMENUDIALOG_H
#define HISTOGRAMEQUALIZATIONERMENUDIALOG_H

#include "menudialog.h"

namespace ribi {

///GUI independent HistogramEqualizationer menu dialog
struct HistogramEqualizationerMenuDialog final : public MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
};

} //~namespace ribi

#endif // HISTOGRAMEQUALIZATIONERMENUDIALOG_H
