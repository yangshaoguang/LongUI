﻿// ui
#include <core/ui_manager.h>
#include <control/ui_label.h>
#include <graphics/ui_graphics_impl.h>

/// <summary>
/// Renders this instance.
/// </summary>
/// <returns></returns>
void LongUI::UILabel::Render() const noexcept {
    // 基本渲染
    Super::Render();
    //if (name_dbg[0] != 't')
    //LUIDebug(Hint) << this->GetTextString() << endl;
    // 前景文本
    const auto rect = this->GetBox().GetContentEdge();
    ColorF color; this->GetForegroundColor(color);
    // 文本偏移
    const float xoffset = rect.left + DEFUALT_TEXT_X_OFFSET;
    const float yoffset = rect.top + DEFUALT_TEXT_Y_OFFSET;
    // 具体渲染
    m_text.Render(UIManager.Ref2DRenderer(), color, { xoffset, yoffset });
}
