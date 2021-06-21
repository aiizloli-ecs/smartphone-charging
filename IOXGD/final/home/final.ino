/* ======== Generate by IOXGD Designer ======== */

/* ========== Bg header ========== */
lv_obj_t* Bg;
LV_IMG_DECLARE(img_bg);
/* ====== END of Bg header ====== */

/* ========== b301Btn header ========== */
static lv_style_t b301Btn_rel_style;
static lv_style_t b301Btn_pr_style;
lv_obj_t* b301Btn;
static lv_style_t b301Btn_label_style;
lv_obj_t* b301Btn_label;
/* ====== END of b301Btn header ====== */

/* ========== b451Btn header ========== */
static lv_style_t b451Btn_rel_style;
static lv_style_t b451Btn_pr_style;
lv_obj_t* b451Btn;
static lv_style_t b451Btn_label_style;
lv_obj_t* b451Btn_label;
/* ====== END of b451Btn header ====== */

/* ========== b601Btn header ========== */
static lv_style_t b601Btn_rel_style;
static lv_style_t b601Btn_pr_style;
lv_obj_t* b601Btn;
static lv_style_t b601Btn_label_style;
lv_obj_t* b601Btn_label;
/* ====== END of b601Btn header ====== */

/* ========== b302Btn header ========== */
static lv_style_t b302Btn_rel_style;
static lv_style_t b302Btn_pr_style;
lv_obj_t* b302Btn;
static lv_style_t b302Btn_label_style;
lv_obj_t* b302Btn_label;
/* ====== END of b302Btn header ====== */

/* ========== b452Btn header ========== */
static lv_style_t b452Btn_rel_style;
static lv_style_t b452Btn_pr_style;
lv_obj_t* b452Btn;
static lv_style_t b452Btn_label_style;
lv_obj_t* b452Btn_label;
/* ====== END of b452Btn header ====== */

/* ========== b602Btn header ========== */
static lv_style_t b602Btn_rel_style;
static lv_style_t b602Btn_pr_style;
lv_obj_t* b602Btn;
static lv_style_t b602Btn_label_style;
lv_obj_t* b602Btn_label;
/* ====== END of b602Btn header ====== */

/* ========== box1txt header ========== */
static lv_style_t box1txt_style;
lv_obj_t* box1txt;
/* ====== END of box1txt header ====== */

/* ========== box2txt header ========== */
static lv_style_t box2txt_style;
lv_obj_t* box2txt;
/* ====== END of box2txt header ====== */

/* ========== msbBg header ========== */
lv_obj_t* msbBg;
LV_IMG_DECLARE(img_msgBg);
/* ====== END of msbBg header ====== */

/* ========== yesBtn header ========== */
lv_obj_t* yesBtn;
LV_IMG_DECLARE(img_no);
/* ====== END of yesBtn header ====== */

/* ========== noBtn header ========== */
lv_obj_t* noBtn;
LV_IMG_DECLARE(img_yes);
/* ====== END of noBtn header ====== */

/* ========== finaltxt header ========== */
static lv_style_t finaltxt_style;
lv_obj_t* finaltxt;
/* ====== END of finaltxt header ====== */

/* ========== cancle1Btn header ========== */
static lv_style_t cancle1Btn_rel_style;
static lv_style_t cancle1Btn_pr_style;
lv_obj_t* cancle1Btn;
static lv_style_t cancle1Btn_label_style;
lv_obj_t* cancle1Btn_label;
/* ====== END of cancle1Btn header ====== */

/* ========== cancle2Btn header ========== */
static lv_style_t cancle2Btn_rel_style;
static lv_style_t cancle2Btn_pr_style;
lv_obj_t* cancle2Btn;
static lv_style_t cancle2Btn_label_style;
lv_obj_t* cancle2Btn_label;
/* ====== END of cancle2Btn header ====== */

/* ========== cancletxt header ========== */
static lv_style_t cancletxt_style;
lv_obj_t* cancletxt;
/* ====== END of cancletxt header ====== */

/* ========== waningtxt header ========== */
static lv_style_t waningtxt_style;
lv_obj_t* waningtxt;
/* ====== END of waningtxt header ====== */

/* ========== warningimg header ========== */
lv_obj_t* warningimg;
LV_IMG_DECLARE(img_warning);
/* ====== END of warningimg header ====== */

/* ========== okBtn header ========== */
lv_obj_t* okBtn;
LV_IMG_DECLARE(img_okBtn);
/* ====== END of okBtn header ====== */


void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFFFFFF);
  style_screen.body.grad_color = lv_color_hex(0xFFFFFF);
  lv_obj_set_style(lv_scr_act(), &style_screen);

  /* ========== Bg ========== */
  Bg = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(Bg, &img_bg);
  lv_obj_align(Bg, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  lv_obj_set_hidden(Bg, false);
  /* ====== END of Bg ====== */

  /* ========== b301Btn ========== */
  lv_style_copy(&b301Btn_rel_style, &lv_style_plain);
  b301Btn_rel_style.body.main_color = lv_color_hex(0x9bd3cb);
  b301Btn_rel_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b301Btn_rel_style.body.radius = 6;
  b301Btn_rel_style.body.border.color = lv_color_hex(0xfcbcbc);
  b301Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b301Btn_pr_style, &lv_style_plain);
  b301Btn_pr_style.body.main_color = lv_color_hex(0x9BD3CB);
  b301Btn_pr_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b301Btn_pr_style.body.radius = 6;
  b301Btn_pr_style.body.border.color = lv_color_hex(0xfcbcbc);
  b301Btn_pr_style.body.border.width = 2;

  b301Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b301Btn, );
  lv_btn_set_style(b301Btn, LV_BTN_STATE_REL, &b301Btn_rel_style);
  lv_btn_set_style(b301Btn, LV_BTN_STATE_PR, &b301Btn_pr_style);
  lv_obj_set_size(b301Btn, 150, 70);
  lv_obj_align(b301Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 130, 180);
  lv_obj_set_click(b301Btn, true);
  lv_obj_set_event_cb(b301Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 1 - 30minutes");

      currPage = 1;
      commandNumber = 1;
      chargerNumber = 1;
      screenTime = millis() / 1000; // ดึงเวลา
    }
  });

  lv_style_copy(&b301Btn_label_style, &lv_style_plain);
  b301Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b301Btn_label_style.text.font = &lv_font_roboto_16;
  b301Btn_label = lv_label_create(b301Btn, NULL);
  lv_label_set_style(b301Btn_label, LV_LABEL_STYLE_MAIN, &b301Btn_label_style);
  lv_label_set_text(b301Btn_label, "30 minute");

  lv_obj_set_hidden(b301Btn, false);
  /* ====== END of b301Btn ====== */

  /* ========== b451Btn ========== */
  lv_style_copy(&b451Btn_rel_style, &lv_style_plain);
  b451Btn_rel_style.body.main_color = lv_color_hex(0x9BD3CB);
  b451Btn_rel_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b451Btn_rel_style.body.radius = 6;
  b451Btn_rel_style.body.border.color = lv_color_hex(0xFCBCBC);
  b451Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b451Btn_pr_style, &lv_style_plain);
  b451Btn_pr_style.body.main_color = lv_color_hex(0x9BD3CB);
  b451Btn_pr_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b451Btn_pr_style.body.radius = 6;
  b451Btn_pr_style.body.border.color = lv_color_hex(0xFCBCBC);
  b451Btn_pr_style.body.border.width = 2;

  b451Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b451Btn, );
  lv_btn_set_style(b451Btn, LV_BTN_STATE_REL, &b451Btn_rel_style);
  lv_btn_set_style(b451Btn, LV_BTN_STATE_PR, &b451Btn_pr_style);
  lv_obj_set_size(b451Btn, 150, 70);
  lv_obj_align(b451Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 130, 270);
  lv_obj_set_click(b451Btn, true);
  lv_obj_set_event_cb(b451Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 1 - 45minutes");

      currPage = 1;
      commandNumber = 2;
      chargerNumber = 1;
      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&b451Btn_label_style, &lv_style_plain);
  b451Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b451Btn_label_style.text.font = &lv_font_roboto_16;
  b451Btn_label = lv_label_create(b451Btn, NULL);
  lv_label_set_style(b451Btn_label, LV_LABEL_STYLE_MAIN, &b451Btn_label_style);
  lv_label_set_text(b451Btn_label, "45 minute");

  lv_obj_set_hidden(b451Btn, false);
  /* ====== END of b451Btn ====== */

  /* ========== b601Btn ========== */
  lv_style_copy(&b601Btn_rel_style, &lv_style_plain);
  b601Btn_rel_style.body.main_color = lv_color_hex(0x9BD3CB);
  b601Btn_rel_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b601Btn_rel_style.body.radius = 6;
  b601Btn_rel_style.body.border.color = lv_color_hex(0xFCBCBC);
  b601Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b601Btn_pr_style, &lv_style_plain);
  b601Btn_pr_style.body.main_color = lv_color_hex(0x9BD3CB);
  b601Btn_pr_style.body.grad_color = lv_color_hex(0x9BD3CB);
  b601Btn_pr_style.body.radius = 6;
  b601Btn_pr_style.body.border.color = lv_color_hex(0xFCBCBC);
  b601Btn_pr_style.body.border.width = 2;

  b601Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b601Btn, );
  lv_btn_set_style(b601Btn, LV_BTN_STATE_REL, &b601Btn_rel_style);
  lv_btn_set_style(b601Btn, LV_BTN_STATE_PR, &b601Btn_pr_style);
  lv_obj_set_size(b601Btn, 150, 70);
  lv_obj_align(b601Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 130, 360);
  lv_obj_set_click(b601Btn, true);
  lv_obj_set_event_cb(b601Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 1 - 60minutes");

      currPage = 1;
      commandNumber = 3;
      chargerNumber = 1;
      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&b601Btn_label_style, &lv_style_plain);
  b601Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b601Btn_label_style.text.font = &lv_font_roboto_16;
  b601Btn_label = lv_label_create(b601Btn, NULL);
  lv_label_set_style(b601Btn_label, LV_LABEL_STYLE_MAIN, &b601Btn_label_style);
  lv_label_set_text(b601Btn_label, "60 minute");

  lv_obj_set_hidden(b601Btn, false);
  /* ====== END of b601Btn ====== */

  /* ========== b302Btn ========== */
  lv_style_copy(&b302Btn_rel_style, &lv_style_plain);
  b302Btn_rel_style.body.main_color = lv_color_hex(0xFCBCBC);
  b302Btn_rel_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b302Btn_rel_style.body.radius = 6;
  b302Btn_rel_style.body.border.color = lv_color_hex(0x9BD3CB);
  b302Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b302Btn_pr_style, &lv_style_plain);
  b302Btn_pr_style.body.main_color = lv_color_hex(0xFCBCBC);
  b302Btn_pr_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b302Btn_pr_style.body.radius = 6;
  b302Btn_pr_style.body.border.color = lv_color_hex(0x9BD3CB);
  b302Btn_pr_style.body.border.width = 2;

  b302Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b302Btn, );
  lv_btn_set_style(b302Btn, LV_BTN_STATE_REL, &b302Btn_rel_style);
  lv_btn_set_style(b302Btn, LV_BTN_STATE_PR, &b302Btn_pr_style);
  lv_obj_set_size(b302Btn, 150, 70);
  lv_obj_align(b302Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 330, 180);
  lv_obj_set_click(b302Btn, true);
  lv_obj_set_event_cb(b302Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 2 - 30minutes");

      currPage = 1;
      commandNumber = 1;
      chargerNumber = 2;
      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&b302Btn_label_style, &lv_style_plain);
  b302Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b302Btn_label_style.text.font = &lv_font_roboto_16;
  b302Btn_label = lv_label_create(b302Btn, NULL);
  lv_label_set_style(b302Btn_label, LV_LABEL_STYLE_MAIN, &b302Btn_label_style);
  lv_label_set_text(b302Btn_label, "30 minute");

  lv_obj_set_hidden(b302Btn, false);
  /* ====== END of b302Btn ====== */

  /* ========== b452Btn ========== */
  lv_style_copy(&b452Btn_rel_style, &lv_style_plain);
  b452Btn_rel_style.body.main_color = lv_color_hex(0xFCBCBC);
  b452Btn_rel_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b452Btn_rel_style.body.radius = 6;
  b452Btn_rel_style.body.border.color = lv_color_hex(0x9BD3CB);
  b452Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b452Btn_pr_style, &lv_style_plain);
  b452Btn_pr_style.body.main_color = lv_color_hex(0xFCBCBC);
  b452Btn_pr_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b452Btn_pr_style.body.radius = 6;
  b452Btn_pr_style.body.border.color = lv_color_hex(0x9BD3CB);
  b452Btn_pr_style.body.border.width = 2;

  b452Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b452Btn, );
  lv_btn_set_style(b452Btn, LV_BTN_STATE_REL, &b452Btn_rel_style);
  lv_btn_set_style(b452Btn, LV_BTN_STATE_PR, &b452Btn_pr_style);
  lv_obj_set_size(b452Btn, 150, 70);
  lv_obj_align(b452Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 330, 270);
  lv_obj_set_click(b452Btn, true);
  lv_obj_set_event_cb(b452Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 2 - 45minutes");

      currPage = 1;
      commandNumber = 2;
      chargerNumber = 2;
      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&b452Btn_label_style, &lv_style_plain);
  b452Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b452Btn_label_style.text.font = &lv_font_roboto_16;
  b452Btn_label = lv_label_create(b452Btn, NULL);
  lv_label_set_style(b452Btn_label, LV_LABEL_STYLE_MAIN, &b452Btn_label_style);
  lv_label_set_text(b452Btn_label, "45 minute");

  lv_obj_set_hidden(b452Btn, false);
  /* ====== END of b452Btn ====== */

  /* ========== b602Btn ========== */
  lv_style_copy(&b602Btn_rel_style, &lv_style_plain);
  b602Btn_rel_style.body.main_color = lv_color_hex(0xFCBCBC);
  b602Btn_rel_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b602Btn_rel_style.body.radius = 6;
  b602Btn_rel_style.body.border.color = lv_color_hex(0x9BD3CB);
  b602Btn_rel_style.body.border.width = 2;

  lv_style_copy(&b602Btn_pr_style, &lv_style_plain);
  b602Btn_pr_style.body.main_color = lv_color_hex(0xFCBCBC);
  b602Btn_pr_style.body.grad_color = lv_color_hex(0xFCBCBC);
  b602Btn_pr_style.body.radius = 6;
  b602Btn_pr_style.body.border.color = lv_color_hex(0x9BD3CB);
  b602Btn_pr_style.body.border.width = 2;

  b602Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(b602Btn, );
  lv_btn_set_style(b602Btn, LV_BTN_STATE_REL, &b602Btn_rel_style);
  lv_btn_set_style(b602Btn, LV_BTN_STATE_PR, &b602Btn_pr_style);
  lv_obj_set_size(b602Btn, 150, 70);
  lv_obj_align(b602Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 330, 360);
  lv_obj_set_click(b602Btn, true);
  lv_obj_set_event_cb(b602Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);
      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);
      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);
      lv_obj_set_hidden(finaltxt, false);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);
      lv_obj_set_hidden(cancletxt, true);
      lv_label_set_text(finaltxt, "Charger 2 - 60minutes");

      currPage = 1;
      commandNumber = 3;
      chargerNumber = 2;

      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&b602Btn_label_style, &lv_style_plain);
  b602Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  b602Btn_label_style.text.font = &lv_font_roboto_16;
  b602Btn_label = lv_label_create(b602Btn, NULL);
  lv_label_set_style(b602Btn_label, LV_LABEL_STYLE_MAIN, &b602Btn_label_style);
  lv_label_set_text(b602Btn_label, "60 minute");

  lv_obj_set_hidden(b602Btn, false);
  /* ====== END of b602Btn ====== */

  /* ========== box1txt ========== */
  lv_style_copy(&box1txt_style, &lv_style_plain);
  box1txt_style.text.color = lv_color_hex(0x658A84);
  box1txt_style.text.font = &lv_font_roboto_16;

  box1txt = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(box1txt, LV_LABEL_STYLE_MAIN, &box1txt_style);
  lv_label_set_long_mode(box1txt, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(box1txt, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(box1txt, "CHARGER1");
  lv_obj_set_size(box1txt, 0, 0);
  lv_obj_align(box1txt, NULL, LV_ALIGN_IN_TOP_LEFT, 170, 140);

  lv_obj_set_hidden(box1txt, false);
  /* ====== END of box1txt ====== */

  /* ========== box2txt ========== */
  lv_style_copy(&box2txt_style, &lv_style_plain);
  box2txt_style.text.color = lv_color_hex(0x658A84);
  box2txt_style.text.font = &lv_font_roboto_16;

  box2txt = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(box2txt, LV_LABEL_STYLE_MAIN, &box2txt_style);
  lv_label_set_long_mode(box2txt, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(box2txt, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(box2txt, "CHARGER2");
  lv_obj_set_size(box2txt, 0, 0);
  lv_obj_align(box2txt, NULL, LV_ALIGN_IN_TOP_LEFT, 360, 140);

  lv_obj_set_hidden(box2txt, false);
  /* ====== END of box2txt ====== */

  /* ========== msbBg ========== */
  msbBg = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(msbBg, &img_msgBg);
  lv_obj_align(msbBg, NULL, LV_ALIGN_IN_TOP_LEFT, 110, 110);

  lv_obj_set_hidden(msbBg, true);
  /* ====== END of msbBg ====== */

  /* ========== yesBtn ========== */
  yesBtn = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(yesBtn, &img_yes);
  lv_obj_align(yesBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 230, 240);

  lv_obj_set_click(yesBtn, true);
  lv_obj_set_event_cb(yesBtn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      int chargerIndex = chargerNumber - 1;
      String warningText = "";
      String chargerString = String(chargerNumber);

      if (commandNumber) {
        oldCommand[chargerIndex] = commandNumber;
        Serial.print("oldCommand[");
        Serial.print(chargerIndex);
        Serial.print("] : ");
        Serial.println(oldCommand[chargerIndex]);
      }

      Serial.print("chargerNumber: ");
      Serial.println(chargerNumber);
      Serial.print("commandNumber: ");
      Serial.println(commandNumber);

      // send command to charger pin
      for (int i = 0; i < numData; i++) {
        digitalWrite(chargerOutput[chargerIndex][i], chargerCommand[commandNumber][i]);
      }
      delay(300);

      bool successfullyCommand = digitalRead(successfullyInput[chargerIndex]);
      Serial.print("successfullyCommand : ");
      Serial.println(successfullyCommand);
      if (successfullyCommand) {
        if (commandNumber) {
          Serial.println("Work Command");
          warningText = "Charger " + chargerString + " on for " + chargerDuration[chargerIndex] + " Minute";
          // lv_label_set_text(waningtxt, "You Can Charge Your Phone Now.");
          chargerStatus[chargerIndex] = true;
        }
        else {
          Serial.println("Cancle Command");
          warningText = "Hold Tracker Button " + chargerString + " for 3 Second in 30 Second.";
          // lv_label_set_text(waningtxt, "Hold Tracker Button for 3 Second in 30 Second.");
          startTime[chargerIndex] = millis() / 1000;
          waitStopCharger[chargerIndex] = true;
          Serial.print("waitStopCharger[");
          Serial.print(chargerIndex);
          Serial.print("] : ");
          Serial.println(waitStopCharger[chargerIndex]);
        }
      }
      else {
        if (commandNumber) {
          Serial.println("ERROR Work Command");
          warningText = "Please Close the Charger Door " + chargerString + " Before Charger";
          commandNumber = 0;
          for (int i = 0; i < numData; i++) {
            digitalWrite(chargerOutput[chargerIndex][i], chargerCommand[commandNumber][i]);
          }
          // lv_label_set_text(waningtxt, "Please Close the Door");
        }
        else {
          Serial.println("ERROR Cancle Command");
          warningText = "Please Close the Charger Door " + chargerString + " Before Stop Charger";
          for (int i = 0; i < numData; i++) {
            digitalWrite(chargerOutput[chargerIndex][i], chargerCommand[oldCommand[chargerIndex]][i]);
          }
        }
        // lv_label_set_text(waningtxt, "Error, Please Try Again.");
      }

      Serial.print("chargerStatus[");
      Serial.print(chargerIndex);
      Serial.print("] = ");
      Serial.println(chargerStatus[chargerIndex]);
      Serial.println();

      currPage = 2;
      screenTime = millis() / 1000;
      warningDisplay(warningText);
    }
  });

  lv_obj_set_hidden(yesBtn, true);
  /* ====== END of yesBtn ====== */

  /* ========== noBtn ========== */
  noBtn = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(noBtn, &img_no);
  lv_obj_align(noBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 470, 240);
  lv_obj_set_click(noBtn, true);
  lv_obj_set_event_cb(noBtn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      currPage = 0;
      homeDisplay();
      screenTime = millis() / 1000;
    }
  });

  lv_obj_set_hidden(noBtn, true);
  /* ====== END of noBtn ====== */

  /* ========== finaltxt ========== */
  lv_style_copy(&finaltxt_style, &lv_style_plain);
  finaltxt_style.text.color = lv_color_hex(0x658A84);
  finaltxt_style.text.font = &lv_font_roboto_16;

  finaltxt = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(finaltxt, LV_LABEL_STYLE_MAIN, &finaltxt_style);
  lv_label_set_long_mode(finaltxt, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(finaltxt, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(finaltxt, "Hello");
  lv_obj_set_size(finaltxt, 0, 0);
  lv_obj_align(finaltxt, NULL, LV_ALIGN_IN_TOP_LEFT, 380, 180);

  lv_obj_set_hidden(finaltxt, true);
  /* ====== END of finaltxt ====== */

  /* ========== cancle1Btn ========== */
  lv_style_copy(&cancle1Btn_rel_style, &lv_style_plain);
  cancle1Btn_rel_style.body.main_color = lv_color_hex(0x9BD3CB);
  cancle1Btn_rel_style.body.grad_color = lv_color_hex(0x9BD3CB);
  cancle1Btn_rel_style.body.radius = 6;
  cancle1Btn_rel_style.body.border.color = lv_color_hex(0xFCBCBC);
  cancle1Btn_rel_style.body.border.width = 4;

  lv_style_copy(&cancle1Btn_pr_style, &lv_style_plain);
  cancle1Btn_pr_style.body.main_color = lv_color_hex(0x9BD3CB);
  cancle1Btn_pr_style.body.grad_color = lv_color_hex(0x9BD3CB);
  cancle1Btn_pr_style.body.radius = 6;
  cancle1Btn_pr_style.body.border.color = lv_color_hex(0xFCBCBC);
  cancle1Btn_pr_style.body.border.width = 4;

  cancle1Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(cancle1Btn, );
  lv_btn_set_style(cancle1Btn, LV_BTN_STATE_REL, &cancle1Btn_rel_style);
  lv_btn_set_style(cancle1Btn, LV_BTN_STATE_PR, &cancle1Btn_pr_style);
  lv_obj_set_size(cancle1Btn, 150, 80);
  lv_obj_align(cancle1Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 130, 270);
  lv_obj_set_click(cancle1Btn, true);
  lv_obj_set_event_cb(cancle1Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();
      lv_obj_set_hidden(Bg, false);

      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);

      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);

      lv_obj_set_hidden(finaltxt, true);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);

      lv_obj_set_hidden(cancletxt, false);

      currPage = 1;
      commandNumber = 0;  // cancle command
      chargerNumber = 1;  // of charger 1
      screenTime = millis() / 1000;
    }
  });

  lv_style_copy(&cancle1Btn_label_style, &lv_style_plain);
  cancle1Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  cancle1Btn_label_style.text.font = &lv_font_roboto_16;
  cancle1Btn_label = lv_label_create(cancle1Btn, NULL);
  lv_label_set_style(cancle1Btn_label, LV_LABEL_STYLE_MAIN, &cancle1Btn_label_style);
  lv_label_set_text(cancle1Btn_label, "Stop Charger 1");

  lv_obj_set_hidden(cancle1Btn, true);
  /* ====== END of cancle1Btn ====== */

  /* ========== cancle2Btn ========== */
  lv_style_copy(&cancle2Btn_rel_style, &lv_style_plain);
  cancle2Btn_rel_style.body.main_color = lv_color_hex(0xFCBCBC);
  cancle2Btn_rel_style.body.grad_color = lv_color_hex(0xFCBCBC);
  cancle2Btn_rel_style.body.radius = 6;
  cancle2Btn_rel_style.body.border.color = lv_color_hex(0x9BD3CB);
  cancle2Btn_rel_style.body.border.width = 4;

  lv_style_copy(&cancle2Btn_pr_style, &lv_style_plain);
  cancle2Btn_pr_style.body.main_color = lv_color_hex(0xFCBCBC);
  cancle2Btn_pr_style.body.grad_color = lv_color_hex(0xFCBCBC);
  cancle2Btn_pr_style.body.radius = 6;
  cancle2Btn_pr_style.body.border.color = lv_color_hex(0x9BD3CB);
  cancle2Btn_pr_style.body.border.width = 4;

  cancle2Btn = lv_btn_create(lv_scr_act(), NULL);
  // lv_obj_set_event_cb(cancle2Btn, );
  lv_btn_set_style(cancle2Btn, LV_BTN_STATE_REL, &cancle2Btn_rel_style);
  lv_btn_set_style(cancle2Btn, LV_BTN_STATE_PR, &cancle2Btn_pr_style);
  lv_obj_set_size(cancle2Btn, 150, 80);
  lv_obj_align(cancle2Btn, NULL, LV_ALIGN_IN_TOP_LEFT, 330, 270);
  lv_obj_set_click(cancle2Btn, true);
  lv_obj_set_event_cb(cancle2Btn, [](lv_obj_t* obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      gd.beep();

      lv_obj_set_hidden(Bg, false);

      lv_obj_set_hidden(b301Btn, true);
      lv_obj_set_hidden(b451Btn, true);
      lv_obj_set_hidden(b601Btn, true);
      lv_obj_set_hidden(b302Btn, true);
      lv_obj_set_hidden(b452Btn, true);
      lv_obj_set_hidden(b602Btn, true);
      lv_obj_set_hidden(box1txt, true);
      lv_obj_set_hidden(box2txt, true);

      lv_obj_set_hidden(msbBg, false);
      lv_obj_set_hidden(yesBtn, false);
      lv_obj_set_hidden(noBtn, false);

      lv_obj_set_hidden(finaltxt, true);
      lv_obj_set_hidden(cancle1Btn, true);
      lv_obj_set_hidden(cancle2Btn, true);

      lv_obj_set_hidden(cancletxt, false);

      currPage = 1;
      commandNumber = 0;  // cancle command
      chargerNumber = 2;  // of charger 1
      screenTime = millis() / 1000;
      // int numData = sizeof(chargerCommand) / 4;
    }
  });

  lv_style_copy(&cancle2Btn_label_style, &lv_style_plain);
  cancle2Btn_label_style.text.color = lv_color_hex(0xFFFFFF);
  cancle2Btn_label_style.text.font = &lv_font_roboto_16;
  cancle2Btn_label = lv_label_create(cancle2Btn, NULL);
  lv_label_set_style(cancle2Btn_label, LV_LABEL_STYLE_MAIN, &cancle2Btn_label_style);
  lv_label_set_text(cancle2Btn_label, "Stop Charger 2");

  lv_obj_set_hidden(cancle2Btn, true);
  /* ====== END of cancle2Btn ====== */

  /* ========== cancletxt ========== */
  lv_style_copy(&cancletxt_style, &lv_style_plain);
  cancletxt_style.text.color = lv_color_hex(0x658A84);
  cancletxt_style.text.font = &lv_font_roboto_16;

  cancletxt = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(cancletxt, LV_LABEL_STYLE_MAIN, &cancletxt_style);
  lv_label_set_long_mode(cancletxt, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(cancletxt, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(cancletxt, "Stop Charger ");
  lv_obj_set_size(cancletxt, 0, 0);
  lv_obj_align(cancletxt, NULL, LV_ALIGN_IN_TOP_LEFT, 400, 180);

  lv_obj_set_hidden(cancletxt, true);
  /* ====== END of cancletxt ====== */

  /* ========== waningtxt ========== */
  lv_style_copy(&waningtxt_style, &lv_style_plain);
  waningtxt_style.text.color = lv_color_hex(0x658A84);
  waningtxt_style.text.font = &lv_font_roboto_16;

  waningtxt = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(waningtxt, LV_LABEL_STYLE_MAIN, &waningtxt_style);
  lv_label_set_long_mode(waningtxt, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(waningtxt, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(waningtxt, "Hold Tracker Button for 3 Second");
  lv_obj_set_size(waningtxt, 0, 0);
  lv_obj_align(waningtxt, NULL, LV_ALIGN_IN_TOP_LEFT, 300, 200);

  lv_obj_set_hidden(waningtxt, true);
  /* ====== END of waningtxt ====== */

  /* ========== warningimg ========== */
  warningimg = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(warningimg, &img_warning);
  lv_obj_align(warningimg, NULL, LV_ALIGN_IN_TOP_LEFT, 380, 110);

  lv_obj_set_hidden(warningimg, true);
  /* ====== END of warningimg ====== */

  /* ========== okBtn ========== */
  okBtn = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(okBtn, &img_okBtn);
  lv_obj_align(okBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 340, 240);

  lv_obj_set_hidden(okBtn, true);
  /* ====== END of okBtn ====== */
}

void homeDisplay() {
  Serial.println("homeDisplay");
  if (chargerStatus[0]) {
    lv_obj_set_hidden(b301Btn, true);
    lv_obj_set_hidden(b451Btn, true);
    lv_obj_set_hidden(b601Btn, true);
    lv_obj_set_hidden(cancle1Btn, false);
  }
  else {
    lv_obj_set_hidden(b301Btn, false);
    lv_obj_set_hidden(b451Btn, false);
    lv_obj_set_hidden(b601Btn, false);
    lv_obj_set_hidden(cancle1Btn, true);
  }

  if (chargerStatus[1]) {
    lv_obj_set_hidden(b302Btn, true);
    lv_obj_set_hidden(b452Btn, true);
    lv_obj_set_hidden(b602Btn, true);
    lv_obj_set_hidden(cancle2Btn, false);
  }
  else {
    lv_obj_set_hidden(b302Btn, false);
    lv_obj_set_hidden(b452Btn, false);
    lv_obj_set_hidden(b602Btn, false);
    lv_obj_set_hidden(cancle2Btn, true);
  }
  lv_obj_set_hidden(Bg, false);
  lv_obj_set_hidden(box1txt, false);
  lv_obj_set_hidden(box2txt, false);
  lv_obj_set_hidden(msbBg, true);
  lv_obj_set_hidden(yesBtn, true);
  lv_obj_set_hidden(noBtn, true);
  lv_obj_set_hidden(finaltxt, true);
  lv_obj_set_hidden(cancletxt, true);
  lv_obj_set_hidden(waningtxt, true);
}

void warningDisplay(String warningTxt) {
  Serial.println("warningDisplay");
  lv_obj_set_hidden(b301Btn, true);
  lv_obj_set_hidden(b451Btn, true);
  lv_obj_set_hidden(b601Btn, true);
  lv_obj_set_hidden(cancle1Btn, true);
  lv_obj_set_hidden(b302Btn, true);
  lv_obj_set_hidden(b452Btn, true);
  lv_obj_set_hidden(b602Btn, true);
  lv_obj_set_hidden(cancle2Btn, true);
  lv_obj_set_hidden(box1txt, true);
  lv_obj_set_hidden(box2txt, true);
  lv_obj_set_hidden(yesBtn, true);
  lv_obj_set_hidden(noBtn, true);
  lv_obj_set_hidden(finaltxt, true);
  lv_obj_set_hidden(cancletxt, true);

  lv_obj_set_hidden(Bg, false);
  lv_obj_set_hidden(msbBg, false);
  lv_label_set_text(waningtxt, warningTxt.c_str());
  lv_obj_set_hidden(waningtxt, false);
}

void timeRemaining(int chargerIdx, String remainTime) {
  if (chargerIdx) {
    lv_label_set_text(cancle1Btn_label, remainTime.c_str());
  }
  else {
    lv_label_set_text(cancle2Btn_label, remainTime.c_str());
  }
}
