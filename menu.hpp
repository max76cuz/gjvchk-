#define SPACING 25

static const char* recoil_weapons[]{ "AK-47", "M249", "LR-300", "MP5", "Custom SMG", "Thompson" };

void Menu()
{
    if (global.menu)
    {
        ImGui::SetNextWindowSize(ImVec2(600, 400), NULL);
        ImGui::Begin(_("Recoil Control"), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);

        ImVec2 pos = ImGui::GetWindowPos();
        ImDrawList* draw = ImGui::GetBackgroundDrawList();
        draw->AddImage((PVOID)global.Image, pos, ImVec2(pos.x + 600, pos.y + 400));

        ImGui::PushFont(global.title);
        ImGui::TextColored(ImColor(200, 255, 0, 255), _("Recoil Control System"));
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));

        ImGui::Checkbox2(_("Enabled"), &global.recoil_enabled);
        ImGui::Checkbox2(_("Auto Detect Weapon"), &global.auto_detect_weapon);
        if (!global.auto_detect_weapon)
        {
            ImGui::Combo(_("Weapon"), &global.selected_weapon, recoil_weapons, IM_ARRAYSIZE(recoil_weapons));
        }

        ImGui::SliderFloatCustom(_("Recoil Strength"), &global.recoil_strength, 0.f, 1.f);
        ImGui::SliderFloatCustom(_("Humanization"), &global.humanization_amount, 0.f, 1.f);
        ImGui::SliderFloatCustom(_("Randomness"), &global.randomness, 0.f, 1.f);
        ImGui::SliderFloatCustom(_("Shot Delay (ms)"), &global.shot_delay, 0.f, 100.f);

        ImGui::Checkbox2(_("Compensate Vertical"), &global.recoil_vertical);
        ImGui::Checkbox2(_("Compensate Horizontal"), &global.recoil_horizontal);

        ImGui::Checkbox2(_("Show Debug Crosshair"), &global.debug_crosshair);
        ImGui::Checkbox2(_("Show FOV Circle"), &global.show_fov_circle);
        if (global.show_fov_circle)
        {
            ImGui::SliderFloatCustom(_("FOV Size"), &global.fov_size, 0.f, 500.f);
        }

        ImGui::End();
    }
}
