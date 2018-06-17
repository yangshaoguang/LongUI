﻿// ui
#include <core/ui_const_sstring.h>
#include <util/ui_unimacro.h>
#include <core/ui_malloc.h>
#include <luiconf.h>
// c++
#include <cassert>

PCN_NOINLINE
/// <summary>
/// Releases this instance.
/// </summary>
/// <returns></returns>
void LongUI::CUIConstShortString::release() noexcept {
    if (m_string != EMPTY) {
        const void* ptr = m_string;
        m_string = EMPTY;
        LongUI::SmallFree(const_cast<void*>(ptr));
    }
}

PCN_NOINLINE
/// <summary>
/// Sets the view.
/// </summary>
/// <param name="view">The view.</param>
/// <returns></returns>
void LongUI::CUIConstShortString::set_view(U8View view) noexcept {
    assert(view.end() - view.begin() < SHORT_MEMORY_LENGTH && "too long");
    // 释放旧的空间
    this->release();
    const size_t len = view.end() - view.begin();
    if (!len) return;
    // 申请新的空间
    if (const auto ptr = LongUI::SmallAllocT<char>(len+1)) {
        std::memcpy(ptr, view.begin(), len);
        ptr[len] = 0;
        m_string = ptr;
    }
}
